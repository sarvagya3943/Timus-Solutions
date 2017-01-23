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
#define rep(i,x,y) for (__typeof(x) i=x;(x<=y?i<=y:i>=y);i=(x<=y?i+1:i-1))
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

int power(int a , int b)
{
    int res = 1 ;
    while(b)
    {
        if(b%2) {
            res = (res * a)%mod ;
        }
        b/=2 ;
        a = (a*a)%mod ;
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
typedef long long LL;
const int MAX = 1005;

int inp[MAX][MAX];
LL sum[MAX][MAX];

void build(int n, int m) {
	//sum array is global, so initailised to 0 initially
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			sum[i][j] = sum[i][j-1] + inp[i][j];
		}
	}
	for(int j=1; j<=m; ++j) {
		for(int i=2; i<=n; ++i) {
			sum[i][j] += sum[i-1][j];
		}
	}
}

//(x1, y1) are lower-most coordinates of submatrix
//(x2, y2) are upper-most coordinates of submatrix
LL query(int x1, int y1, int x2, int y2) {
	return sum[x2][y2] + sum[x1-1][y1-1] - sum[x2][y1-1] - sum[x1-1][y2];
}
int32_t main()
{
    fast;
    int n ;
    cin >> n ;
    rep(i,1,n)rep(j,1,n)cin>>inp[i][j] ;
    build(n,n) ;
    int ans = -1e5 ;
    rep(x2,1,n)rep(y2,1,n)
    {
        rep(x1,1,x2)rep(y1,1,y2)
        {
            int temp = query(x1,y1,x2,y2) ;
            ans = max(ans , temp) ;
        }
    }
    cout << ans ;
    return 0;
}
