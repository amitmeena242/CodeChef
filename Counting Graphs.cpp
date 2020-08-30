#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
 
#include<bits/stdc++.h>
 
using namespace std;
#define ll long long 
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ull unsigned long long
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ff first
#define ss second
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0); 
#define nl "\n"
#define sz(a) (int)(a).size() 
#define all(a) (a).begin(),(a).end()
#define fl(a,x) memset(a,x,sizeof(a));
#define pt(a,x) cout << get<x>(a) << " " ;  
#define mt make_tuple 
#define vec vector
 
#define int long long 
 
const int mod = (int) 1e9 + 7 ;
const int MOD = (int) 998244353 ;
const int INF = (int) 1e18 ;
 
typedef vector<int> vii;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef vector<vector<int> > vv;
 
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
 
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
 cerr << *it << " = " << a << endl;
 err(++it, args...);
}
  
int power(int a,int b) {
 a %= mod ; 
 if(b == 0 ) return 1;
 int p = power(a,b/2) % mod ;
 p = p * p % mod ;
 return b & 1 ? p * a % mod : p ; 
}

const int mxN = 2e5 + 5; 
const int M = (int) 1e9 + 7 ; 

ll fact[mxN];
ll ifact[mxN];

ll invMod(ll a) {
 return power(a,M-2) % M ;
}
void factorial() {
 fact[0] = 1 ;
 for(ll i = 1;i< mxN;++i) 
  fact[i] = ( i * fact[i-1] ) % M ;
}

void inverseFact() {
 ifact[mxN-1] = invMod(fact[mxN-1]) ; 
 
 for(ll i = mxN-1 ; i>0 ;--i) 
  ifact[i-1] = ( ifact[i] * i ) % M ;
}

ll nCr(ll n, ll r) {
 if (n < r || r < 0 || n < 0) return 0;
 ll res = (ifact[r] * ifact[n-r]) % M ;
 res = ( res * fact[n]) % M ;
 return res ;
}

void solve() {
 int n,m; cin >> n >> m ;

 int h[n] = {} ; 
 h[0] = 1 ;

 int a[n]; rep(i,1,n) cin >> a[i] , h[a[i]]++ ;

 for(int i = 1 ; i < n ; ++i) {
  if(h[i]>0 and h[i-1] == 0 ) {
   cout << 0 << nl ; return ; 
  }
 }

 int dp[n]; dp[0] = 1 ;

 for(int i = 1 ; i < n ; ++i ) {
  dp[i] = (dp[i-1] * power(h[i-1], h[i])) % mod ; 
 }

 int al = 0 ;
 rep(i,1,n) al += (h[i] * (h[i]-1) /2 ) ;

 int e = m - n + 1 ;

 if(e == 0 ) {
  for(int i = 1 ; i < n ; ++i ) if(h[i] == 0 ) {
   cout << dp[i-1] << nl ; return ; 
  }
  cout << dp[n-1] << nl ; return ; 
 }

 if(al < e) { cout << 0 << nl ; return ; }

 int ans = 1 ; 

 for(int i = al-e+1 ; i <= al ; ++i) {
  ans = (ans * i) % mod ; 
 }

 int b = 1; 
 for(int i = 1 ; i <= e ; ++i ) b = b * i % mod ; 

 ans = (ans * power(b,mod-2)) % mod ; 

 rep(i,1,n) {
  if(h[i] == 0) {
   cout << (dp[i-1] * ans ) % mod << nl ;
   return ;  
  }
 }
 cout << dp[n-1] * ans % mod << nl ;
}

int32_t main() {
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif   
    // factorial(); 
    // inverseFact() ;
    fast;
 int t; cin >> t; while(t--) 
  solve() ;
 
 // cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
 return 0;
}
