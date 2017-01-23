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
int cnt ;
int dp[905][8105] ;
int solve(int sum , int sumsq)
{
    if(sum == 0 && sumsq == 0) return 0 ;
    if(sum <= 0 || sumsq <= 0) return mod ;
    int &res = dp[sum][sumsq] ;
    if(res != -1) return res ;
    res = mod ;
    for(int digit = 1 ; digit < 10 ; ++digit) {
        res = min(res , 1 + solve(sum - digit , sumsq - digit*digit)) ;
    }
    return res ;
}
void go(int sum , int sumsq)
{
    if(sum == 0 && sumsq == 0) return ;
    for(int digit = 1 ; digit < 10 ; ++digit) {
        if(solve(sum,sumsq) == 1 + solve(sum - digit , sumsq - digit*digit)) {
            cout << digit ;cnt += 1 ;
            go(sum - digit , sumsq - digit*digit) ;
            return ;
        }
    }
    return ;
}
int32_t main()
{
    fast;
    memset(dp,-1,sizeof(dp)) ;
    int sum , sumsq ;
    int t ;
    cin >> t ;
    while(t--) {
        cin >> sum >> sumsq ;
        cnt = 0 ;
        if(sum > 900 || sumsq > 8100) {
            cout << "No solution\n" ;
        }
        else if(solve(sum,sumsq) > 100) {
            cout << "No solution\n" ;
        }
        else {
            go(sum , sumsq) ;
            assert(cnt <= 100) ;
            cout << "\n" ;
        }
    }
    return 0;
}

