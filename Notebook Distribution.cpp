#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 


using namespace __gnu_pbds; 
using namespace std;

typedef long long int ll;
typedef long long unsigned int llu;
const int INF = 0x3f3f3f3f;

inline int read()
{
    register int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return (f==1)?x:-x;
}

#define ff first
#define ss second
#define ins insert
#define tc int t; cin>>t; while(t--)
#define endl "\n"

#define  sync ios_base::sync_with_stdio(false);  cin.tie(NULL);
#define pb push_back
#define pf pop_front
#define mp make_pair
#define all(v) v.begin(),v.end()

#define mpi unordered_map<ll, ll>
#define pr pair<ll, ll>
#define vi vector<ll>
#define vc vector<char>

#define mpc unordered_map<char, ll>
#define it_loop(it,m) for(auto it = m.begin(); it!=m.end(); it++)
#define rep(i,n) for(ll i=0;i<n;i++)
#define repx(i,begin, end) for(ll i=begin; i<=end;i++)

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define mod 1e9+7
#define count_ones __builtin_popcountl              // #ones in binary rep.
#define what_is(x) cerr << #x << " is " << x << endl  //#x -> actual name of variable

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define eb emplace_back                    // faster than push_back 
#define mt make_tuple                        //  for returning more than one value with tie(args ...) = tuple
#define fill(a,n,start) iota(a,a+n,start)    // fill array in increasing order

#define shuffle(a,n) shuffle(a,a+n,default_random_engine(0))
#define print_arr(a,n) rep(i,n) cout<<a[i]<<endl
#define read_arr(a,n) rep(i,n) cin>>a[i]
#define ook order_of_key   // ook(n) It returns to the number of items that are strictly smaller than our item n

#define nds new_data_set    //pbds array
#define fbo find_by_order   // fbo(i), returns an iterator at the ith index

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

/* gcd __gcd(a,b)
 * sparse_table: st[i][j] = f(st[i][j-1],st[i+(1<<(j-1))][j-1])
 * sparse_table: for range query in immutable array
 * modified queue: stack<pair<ll,ll>> s1,s2   s1->add,  s2->delete
 * long long binpow(long long a, long long b) {    long long res = 1;while (b > 0) {if (b & 1)res = res * a;a = a * a;b >>= 1;}return res;}
 * " \n"[0] is ' ' and " \n"[1] is '\n'
 * we can also use ignore keyword in tie to ignore a value ->  tie(b, ignore, a, ignore)
 * 0 based indexing in pbds ordered_set
 * add(l,x) & add(r+1,-x) for BIT range update point query
 * use scanf and printf insted of fastio
 * gcc optimizations work best with arrays not vectors
 * use int till 1e5
*/


void solve(){
	int n,k;
	cin>>n>>k;
	ll a[n];
	ll sum=0,mx=-1;
	rep(i,n){
		cin>>a[i];
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	ll x = sum/k;
	

	ll l=0,r=mx;
	ll ans=-1;
	while(l<=r){
		
		ll mid = (l+r)/2;
		ll y=0;
		for(int i=0;i<n && mid>0;i++){
			y+=a[i]/mid;
		}
		//error(l,r,mid,y)

		if(y<k)
		 r=mid-1;
		 else{
			ans=max(ans,mid);
			 l=mid+1;
			 
		 }
		
	}
	if(ans==-1) cout<<x<<endl;
	else
	cout<<ans<<endl;
	
}

int main(){
  sync;
  tc{ solve(); }
  //solve();
}
