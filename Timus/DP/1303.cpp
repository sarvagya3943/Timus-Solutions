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
const int maxn = 1e5 + 5 ;
struct line {
    int l , r ;
    line () {}
    line (int _l , int _r) {
        l = _l , r = _r ;
    }
    bool operator < ( line X) const{
        return r < X.r ;
    }
} ;
int M ;
vector<line> arr , ans;
bool cmp(line a,line b) {
    return a.l < b.l ;
}
int32_t main()
{
    fast;
    cin >> M ;
    for(;;) {
        line temp ;
        cin >> temp.l >> temp.r ;
        if(temp.l == 0 && temp.r == 0) {
            break ;
        }
        arr.pb(temp) ;
    }
    sort(all(arr) , cmp ) ;
    int start = 0 ;
    int pos = 0 ;
    bool can = true ;
    while(start < M && can) {
        priority_queue<line> Q ;
        while(pos < arr.size() && arr[pos].l <= start) {
            if(arr[pos].r > start) {
                Q.push(arr[pos]) ;
            }
            pos += 1 ;
        }
        if(Q.empty()) can = false ;
        else {
            line temp = Q.top() ;
            ans.pb(temp) ;
            start = temp.r ;
        }
    }
    if(!can) cout << "No solution\n" ;
    else {
        cout << ans.size() << endl ;
        for(auto it : ans) {
            cout << it.l << " " << it.r << endl ;
        }
    }
    return 0;
}


