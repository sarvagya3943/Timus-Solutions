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
const int maxn = 4001 ;
string s ;
int n;
int dp[maxn] ;
bool is_palin[maxn][maxn] ;
int solve(int index)
{
    if(index < 0 ) return 0 ;
    int &res = dp[index] ;
    if(res != -1) return res ;
    res = 1e9 ;
    for(int i = index ; i >= 0 ; --i) {
        if(is_palin[i][index]) {
            res = min(res , 1 + solve(i-1)) ;
        }
    }
    return res ;
}
void go(int r)
{
    if(r < 0) return ;
    int res = solve(r) ;
    int l = -1 ;
    for(int i = r ; i >= 0 ; --i) {
         if(is_palin[i][r] && solve(i-1) + 1 == res) {
                l = i ;
                break ;
         }
    }
    go(l-1) ;
    for(int i = l ; i <= r ; ++i) {
        cout << s[i] ;
    }
    cout << " " ;
    return ;
}
int32_t main()
{
    fast;
    cin >> s ;
    n = s.size() ;
    memset(dp,-1,sizeof(dp)) ;
    for(int i = 0 ; i < n ; ++i) is_palin[i][i] = true ;
    for(int i = 0 ; i+1 < n ; ++i) {
        if(s[i] == s[i+1]) {
            is_palin[i][i+1] = true ;
        }
    }
    for(int len = 3 ; len <= n ; ++len) {
        for(int i = 0 ; i + len - 1 < n ; ++i) {
            int j = i + len - 1 ;
            if(s[i] == s[j]) {
                if(is_palin[i+1][j-1]) {
                    is_palin[i][j] = true ;
                }
            }
        }
    }
    cout << solve(n-1) << endl ;
    go(n-1) ;
    return 0;
}


