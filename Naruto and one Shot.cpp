#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ull unsigned long long int
#define ll long long int
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define MOD (ull)(double)(1e9 + 7)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vb vector<bool>
#define vd vector<double>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>
#define pull pair<ull, ull>
#define F first
#define S second
#define m_p make_pair
#define debug(x) cout << #x << " " << x << endl
#define printArr(a, start, end)for(int i=start ; i<end ; ++i)cout << a[i] << " ";cout << '\n';
#define readArr(a, start, end)for(int i=start ; i<end ; ++i)cin >> a[i];
#define read2D(mat, n, m)for(int i=0 ; i<n ; ++i)for(int j=0 ; j<m ; ++j)cin >> mat[i][j];

const long double PI = 3.141592653589793238462643383279502884197169399;

// Find Set LSB = (x&(-x)), isPowerOfTwo = (x & (x-1))

vvi Tree;
vb vis;
int el, mx;
int n;

int dfs(int node){
	vis[node] = 1;
	int child=0;
	int sum=0;
	for(int& to : Tree[node]){
		if(!vis[to]){
			int res = dfs(to);
			child = max(child, res);
			sum += res;
		}
	}
	
	int rest = n - (sum + 1);
	int contenders = max(child, rest);
	if(contenders == mx){
		el = min(el, node);
	}
	if(contenders < mx){
		mx = contenders;
		el = node;
	}
	++sum;
	
	return sum;
}

void solve(){
	cin >> n;
	
	Tree = vvi(n);
	int u, v;
	for(int i=0 ; i<n-1 ; ++i){
		cin >> u >> v;
		--u, --v;
		Tree[u].pb(v);
		Tree[v].pb(u);
	}
	
	vis = vb(n, 0);
	mx=INT_MAX;el = INT_MAX;
	dfs(0);
	
	cout << el+1 << " " << mx << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << fixed << setprecision(10);
	
	int tt=1;
	cin >> tt;
	
	while(tt--){
		solve();
	}
}
