
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
#define mod 1000000009
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
int n ;
int dp[10005][10][10][2] ;
bool isprime[1005] ;
int solve(int index , int prev , int pprev , int is)
{
    if(index > n) {
        return is ;
    }
    int &res = dp[index][prev][pprev][is] ;
    if(res != -1) return res ;
    res = 0 ;
    int start = (index > 1) ? 0 : 1 ;
    rep(d,start,9)
    {
        int num = pprev * 100 + prev * 10 + d ;
        int new_is = is ;
        if(index > 2) new_is &= isprime[num] ;
        if(index > 2 && pprev == 0) new_is = false ;
        res += solve(index + 1 , d , prev , new_is) ;
        res %= mod ;
    }
    return res ;
}
int32_t main()
{
    fast;
    memset(isprime,true,sizeof(isprime)) ;
    cin >> n ;
    memset(dp,-1,sizeof(dp)) ;
    isprime[1] = isprime[0] = false ;
    for(int i = 2 ; i <= 1000 ; ++i) {
        if(isprime[i]) {
            for(int j = i*i ; j <= 1000 ; j += i) {
                isprime[j] = false ;
            }
        }
    }
    cout << solve(1,0,0,1) << endl ;
    return 0;
}
