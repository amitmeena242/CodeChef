#include<bits/stdc++.h>
using namespace std;

#define int             long long
#define ld              long double
#define fi              first
#define se              second
#define pb              push_back
#define mp              make_pair
#define fo(i,n)         for(i=0;i<n;i++)
#define fo1(i,n)        for(i=1;i<=n;i++)
#define foab(i,a,b)     for(i=a;i<=b;i++)
#define of(i,n)         for(i=n-1;i>=0;i--)
#define of1(i,n)        for(i=n;i>=1;i--)
#define ofab(i,a,b)     for(i=a;i>=b;i--)
#define sq(a)           (a)*(a)
#define all(x)          x.begin(),x.end()
#define rall(x)         x.rbegin(),x.rend()
#define sortall(x)      sort(all(x))
#define sortrall(x)     sort(rall(x))
#define clr(x)          memset(x,0,sizeof(x))
#define tr(it, a)       for(auto it=a.begin();it!=a.end();it++)
#define pii             pair<int,int>
#define mk(arr,n,type)  type *arr=new type[n];
#define vi              vector<int>
#define vpii            vector<pii>
#define si              set<int>
#define spii            set<pii>
#define usi             unordered_set<int>
#define uspii           unordered_set<pii>
#define mii             map<int,int>
#define umii            unordered_map<int,int>
#define pqmx            priority_queue<int>
#define pqmn            priority_queue<int,vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define trailzrobits(x) __builtin_ctzll(x)
#define leadzrobits(x)  __builtin_clzll(x)
#define paritybits(x)   __builtin_parityll(x)
#define gcd             __gcd
#define lcm(x, y)       (x*y)/gcd(x,y)
#define endl            '\n'
#define sz(s)           (int)s.size()
#define sp(x,y)         fixed<<setprecision(y)<<x
const int mod = 1000000007;
const int inf = 1000000000000000000;
const ld PI = 3.1415926535897932384626;
const ld eps = 1e-12;
void __print(int32_t x) {cout<<x;}
void __print(int x) {cout<<x;}
void __print(double x) {cout<<x;}
void __print(ld x) {cout<<x;}
void __print(float x) {cout<<x;}
void __print(bool x) {cout<<(x?"true":"false");}
void __print(char x) {cout <<'\''<<x<<'\'';}
void __print(const char *x) {cout <<'\"' <<x<<'\"';}
void __print(const string &x) {cout<<'\"'<<x<<'\"';}
template<typename T,typename V>     void __print(const pair<T,V> &x) {cout<<'{';__print(x.first);cout<<',';__print(x.second);cout<<'}';}
template<typename T>                void __print(const T &x) {int f=0;cout<<'{';for(auto &i:x)cout<<(f++?",":""),__print(i);cout<<"}";}void _print(){cout<<"]\n";}
template <typename T,typename... V> void _print(T t, V... v) {__print(t);if(sizeof...(v))cout<<", ";_print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cout<<"["<<#x<<"]=[";_print(x)
#else 
#define dbg(x...)
#endif
int powerm(int base,int exp) {int res=1;base%=mod;while(exp>0){if(exp&1)res=(res*base)%mod;base=(base*base)%mod;exp=exp>>1;}return res;}
int power(int base,int exp) {int res=1;while(exp>0){if(exp&1)res=res*base;base=base*base;exp=exp>>1;}return res;}
float powerNeg(float base,int exp) {float temp;if(exp==0)return 1;temp=powerNeg(base,exp/2);if(exp%2==0)return temp*temp;else{if(exp>0)return base*temp*temp;else return (temp*temp)/base;}}
int modinv(int exp) {return powerm(exp,mod-2);}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



const int N=1e3+5,M=N;
int dp[N][N];
bool rec(vi &a,int i,int k){

    if(k==0) return 1;
    if(i==a.size()) return 0;

    if(dp[i][k]!=-1) return dp[i][k];
    
    bool ok=0;
    if(k>=a[i]) ok=rec(a,i+1,k-a[i]);
    return dp[i][k]=(ok | rec(a,i+1,k));
}
void solve(){
    
    int i,j,k;
    int n; cin>>k>>n;
    vi a(n); fo(i,n) cin>>a[i];
    
    memset(dp,-1,sizeof(dp));
    cout<<rec(a,0,k)<<endl;
}




int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t,T=1;
    cin>>T;
    fo1(t,T){
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    // cout<<endl<<"Times Elapsed:"<<1.0*clock()/CLOCKS_PER_SEC<<"sec";
    return 0;
}
