/*
ye mera template hai
apna khud likho bc :P
*/

/*
Author : Sarvagya Agarwal
*/

#include<bits/stdc++.h>
using namespace std;

//defines
#define openin freopen("input.txt","r",stdin)
#define openout freopen("output.txt","w",stdout)
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long
#define int long long
#define mod 1000000007
#define repr(i,x,y) for (__typeof(x) i=x;i>=y;i--)
#define rep(i,x,y) for (__typeof(x) i=x;i<=y;i++)
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

/* Print pair */
template <typename T,typename S>
ostream & operator << (ostream &os , const pair<T,S> &v) {
    os << "(" ;
    os << v.first << "," << v.second << ")" ;
    return os ;
}
/* Print vector */
template <typename T>
ostream & operator << (ostream &os , const vector<T> &v) {
    os << "[" ;
    int sz = v.size() ;
    for(int i = 0 ; i < sz ; ++i) {
        os << v[i] ;
        if(i!=sz-1)os << "," ;
    }
    os << "]\n" ;
    return os ;
}
/* Print set */
template <typename T>
ostream & operator << (ostream &os , const set<T> &v) {
    T last = *v.rbegin() ;
    os << "[" ;
    for(auto it : v) {
        os << it  ;
        if(it != last) os << "," ;
    }
    os << "]\n" ;
    return os ;
}
/* Print Map */
template <typename T,typename S>
ostream & operator << (ostream &os , const map<T,S> &v) {
    for(auto it : v) {
        os << it.first << " : " << it.second << "\n" ;
    }
    return os ;
}
int power(int a , int b)
{
    int res = 1 ;
    while(b)
    {
        if(b%2) {
            res = (res * a) % mod ;
        }
        b/=2 ;
        a = (a*a) % mod ;
    }
    return res ;
}

//debug
#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
		cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
string s ;
int n ,dp[105][105];
int solve(int l,int r)
{
    if(l > r) return 0 ;
    int &res = dp[l][r] ;
    if(res != -1) return res ;
    res = 1 + solve(l + 1, r) ;
    if(s[l]=='('|| s[l]=='[') {
        for(int i = l + 1 ; i <= r ; ++i) {
            if((s[l]=='(' && s[i] == ')') || (s[l]=='['&& s[i]==']')) {
                res = min(res , solve(l + 1 , i - 1) + solve(i + 1,r)) ;
            }
        }
    }
    return res ;
}
void go(int l,int r)
{
    if(l>r)return ;
    int res = solve(l,r) ;
    if(1 + solve(l+1,r) == res) {
        if(s[l] == '(' || s[l] == ')') {
            cout << "()" ;
        }
        else cout << "[]" ;
        go(l+1,r) ;
        return ;
    }
    rep(i,l+1,r) {
        if(((s[l]=='('&&s[i]==')') || (s[l]=='['&&s[i]==']')) && res ==solve(l+1,i-1)+solve(i+1,r)){
            if(s[l]=='(') {
                cout << "(" ;
                go(l+1,i-1) ;
                cout << ")" ;
                go(i+1,r) ;
            }
            else {
                cout << "[" ;
                go(l+1,i-1) ;
                cout << "]" ;
                go(i+1,r) ;
            }
            return ;
        }
    }
    return  ;
}
int32_t main()
{
    fast;
    cin >> s ;
    n = s.size() ;
    memset(dp,-1,sizeof(dp)) ;
    go(0,n-1) ;
    return 0;
}


