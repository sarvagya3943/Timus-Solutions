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
const int maxn = 1e2 + 5 ;
int n , q ;
int sz[maxn] ,arr[maxn] , tapp[maxn] ;
vector<pair<int,int> > graph[maxn] ;
pair<int,int> child[maxn] ;
int dp[maxn][maxn] ;
void pre(int node,int par)
{
    sz[node] = 1 ;
    tapp[node] = arr[node] ;
    for(auto it : graph[node]) {
        if(it.first != par) {
             arr[it.first] = it.second ;
             if(child[node].first != 0) child[node].second = it.ff ;
             else child[node].first = it.ff ;
             pre(it.first,node) ;
             sz[node] += sz[it.ff] ;
             tapp[node] += tapp[it.ff] ;
        }
    }
}
void dfs(int node)
{
    dp[node][sz[node]] = tapp[node] ;
    if(child[node].ff==0) return ;
    if(child[node].ff) {
        dfs(child[node].ff) ;
    }
    if(child[node].ss) {
        dfs(child[node].ss) ;
    }
    for(int cuts = 1 ; cuts <= q ; ++cuts) {
        for(int l = 0 ; l <= cuts ; ++l) {
            dp[node][cuts] = min(dp[node][cuts] , dp[child[node].ff][l] + dp[child[node].ss][cuts-l]) ;
        }
    }
}
int32_t main()
{
    fast;
    cin >> n >> q ;
    int total = 0 ;
    for(int i = 1 ; i < n ; ++i) {
        int u , v , w ;
        cin >> u >> v >> w ;
        total += w ;
        graph[u].push_back(make_pair(v,w)) ;
        graph[v].push_back(make_pair(u,w)) ;
    }
    rep(i,1,n)rep(j,1,n)dp[i][j]=mod ;
    pre(1,0) ;
    q = n - 1 - q ;
    dfs(1) ;
    cout << total - dp[1][q] << endl ;
    return 0;
}


