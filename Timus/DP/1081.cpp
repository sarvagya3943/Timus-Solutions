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
int n , k ;
vector<int> dig ;
int sz ;
int dp[45][10][2] ;
int f(int index,int prev,int preless)
{
    if(index == sz) {
        return 1 ;
    }
    int &res = dp[index][prev][preless] ;
    if(res != -1) return res ;
    res = 0 ;
    int lim = preless ? 1 : dig[index] ;
    rep(d,0,lim) {
        if(d == 1 && prev == 1) {

        }
        else res += f(index + 1 , d ,preless || d < dig[index] ) ;
    }
    return res ;
}
int solve(int num)
{
    memset(dp,-1,sizeof(dp)) ;
    dig.clear() ;
    for(int i = 0 ; i < n ; ++i) {
        dig.pb(num%2) ;
        num /= 2 ;
    }
    sz = dig.size() ;
    reverse(all(dig)) ;
    return f(0,0,0) ;
}
int32_t main()
{
    fast;
    cin >> n >> k ;
    int lo = 0 , hi  = (1ll<<n)-1 , mi,ans=-1 ;
    while(lo <= hi) {
        mi = (lo + hi)/2 ;
        int cnt = solve(mi) ;
        if(cnt >= k) {
            ans = mi ;
            hi = mi - 1 ;
        }
        else lo = mi + 1 ;
    }
    if(ans == -1) {
        cout << -1 << endl ;
        return 0 ;
    }
    string res = "" ;
    for(int i = 0 ; i < n ; ++i) {
        if(ans % 2) {
            res += "1" ;
        }
        else res += "0" ;
        ans /= 2 ;
    }
    reverse(all(res)) ;
    cout << res ;
    return 0;
}


