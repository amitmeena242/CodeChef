#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define AfterDecimal(n) cout << fixed << setprecision(n);
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define bits(x) __builtin_popcount(x)
#define int long long


using namespace __gnu_pbds;
using namespace std;

template <class T> T printr(T p){ cout << p << '\n'; return 0; }
template <class T> T printe(T p){ cout << p << '\n'; exit(0); }
template <class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template <class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }


//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef tree<int, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update>
    ordered_set;

#ifdef LOCAL
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << "# "<< name << " = " << arg1 << '\n';
}
template<typename Arg1, typename... Args>
void __f(const char* names, Arg1 && arg1, Args &&... args){
        const char* comma = strchr(names + 1 ,',');
        cout << "# ";
        cout.write(names, comma - names)<< " = " << arg1 << " | ";
        __f(comma + 1, args...);
}
#else
#define debug(...) 36
#endif

std::mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int ri(int a, int b) {
    return uniform_int_distribution<int>(a, b)(rng);
}

ll power(ll x, ll y, ll p){
   ll res = 1;
   x = x % p;
   while (y > 0) {
      if (y & 1)
         res = (res * x) % p;
      y = y >> 1;
      x = (x * x) % p;
   }
   return res;
}

const ll INF = (ll)(8e18);
const ll MOD = (ll)(1e9 + 7);
const ll HMOD = (ll)4222234727;
const ll Hashprime = (ll)31;

const int maxn = 500010;

std::vector<int> g[maxn], pval[maxn];
std::vector< pair <pii, int> > Q[maxn];
int BIT[maxn];
vector <pii> V;
int sz[maxn], nr[maxn], top[maxn], pa[maxn];
int timer;

void dfsz(int v, int p){
  pa[v] = p;
	sz[v] = 1;
	auto it = find(all(g[v]), p);
	if (it != g[v].end()) g[v].erase(it);
	for(auto u : g[v]){
		dfsz(u, v);
		sz[v] += sz[u];
	}
	sort(all(g[v]), [&](int a, int b) {return sz[a] > sz[b];});
}

void dfsh(int v, int h){
  nr[v] = ++timer;
  top[v] = h;
  for (auto u : g[v]){
    dfsh(u, u == g[v][0] ? h : u);
  }
}

void update(int x, int val){
     assert(x > 0);
     for(; x < maxn; x += (x & -x)){
         BIT[x] += val;
     }
}

int query(int x){
   int val = 0;
   for(;x > 0; x -= (x & -x)){
       val += BIT[x];
   }
   return val;
}

int get(int x, int y){
  if(x > y) swap(x, y);
	return query(y) - query(x - 1);
}

int ans(int u, int v){
   int fans = 0;
    while(top[u] != top[v]){
        if(nr[u] < nr[v]) swap(u, v);
        fans += get(nr[top[u]], nr[u]);
        u = pa[top[u]];
    }
    if (nr[u] < nr[v]) swap(u, v);
  	fans += get(nr[v], nr[u]);
    return fans;
}

int32_t main(){
    IOS;
    #ifndef ONLINE_JUDGE
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    while(t--){
       int n,q; cin >> n >> q;
       for(int i = 1;  i < n; i++){
           int u,v; cin >> u >> v;
           g[u].push_back(v);
           g[v].push_back(u);
       }
       int srt = 0;
       for(int i = 1; i <= n; i++){
            int vval; cin >> vval;
            V.push_back({vval, i});
            pval[vval].push_back(i);
            srt = max(srt, vval);
       }
       dfsz(1, 1);
       dfsh(1, 1);
       sort(all(V));
        for(auto  i : V){
            update(nr[i.second], i.first);
        }
        for(int i = 1; i <= q; i++){
            int a,b,w; cin >> a >> b >> w;
            srt = max(srt, w);
            Q[w].push_back({{a, b}, i});
        }
        std::vector<int> v(q + 1, 0);
        for(int i = srt; i >= 0; i--){
           for(auto j : Q[i]){
              v[j.second] = ans(j.first.first, j.first.second);
           }
           for(auto j : pval[i]){
              update(nr[j], -i);
           }
        }
        for(int i = 1; i <= q; i++) cout << v[i] << '\n';

    }
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}
