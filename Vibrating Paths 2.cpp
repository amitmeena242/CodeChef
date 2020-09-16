#include<bits/stdc++.h>
#define ALL(c) begin(c), end(c)
using namespace std;
using ll = long long;
using ld = long double;

const int MAX_N = 1e4+4;
int get_edges_limit(int,int);
int get_edges_limit_to_check_Kpartite(int,int);

#ifdef BIZON
	#define seed 288
#else
	#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
#endif

mt19937 rnd(seed);
#define rand

struct dsu {
	vector<int> p, sz;
	dsu(int n): sz(n,1), p(n) {
		iota(ALL(p),0);
	}
	int get(int i){
		int v = i;
		while(v!=p[v]) v = p[v];
		while(i!=p[i]) i = exchange(p[i],v);
		return v;
	}
	bool unite(int i, int j){
		i = get(i);
		j = get(j);
		if(i==j) return false;
		if(sz[i]<sz[j]) swap(i,j);
		p[j] = i;
		sz[i]+=sz[j];
		return true;
	}
};


template<class T> inline bool equals(const T& x, const T& y){ return x==y; }
inline bool equals(const ld &x, const ld &y){ return abs(x-y)<1e-9; }

template<typename T>
struct iheap {
	vector<T> vals;
	vector<size_t> t;
	size_t d;
	
	vector<bool> removed;
	
	void mrg(int i){
		int l = t[i*2], r = t[i*2+1];
		if(removed[l]) t[i] = r; else
		if(removed[r]) t[i] = l; else {
			const T &x = vals[l];
			const T &y = vals[r];
			t[i] = x < y || equals(x,y) && rnd()%2 ? l : r;
		}
	}
	
	iheap(const vector<T> &init){
		d = size(init);
		vals = init;
		t.resize(d*2);
		iota(begin(t)+d, end(t), 0);
		removed.assign(d, false);
		for(int i=d-1;i;--i) mrg(i);
	}
	
	void set_value(size_t i, const T &val){
		vals[i] = val;
		for(i=(i+d)>>1 ;i; i>>=1) mrg(i);
	}
	
	void remove(size_t i){
		removed[i] = true;
		for(i=(i+d)>>1 ;i; i>>=1) mrg(i);
	}
	
	size_t get_index_of_min(){
		return t[1];
	}
};


using graph = vector<vector<int>> ;
struct edge {
	int i,j,x;
	
	edge(){}
	edge(int i, int j): i(i), j(j), x(i^j) {};
	
	inline int from(const int &v) const {
		return v^x;
	}
};

void erase(vector<int> &v, int x){
	auto it = find(ALL(v),x);
	//assert(it!=end(v));
	v.erase(it);
}

void erase_unordered(vector<int> &v, int x){
	auto it = find(ALL(v),x);
	//assert(it!=end(v));
	*it = v.back();
	v.pop_back();
}


void read(int &n, int &m, int &k, graph &g, vector<edge> &edges, vector<int> &c){
	cin>>n>>m>>k;
	c.resize(n);
	for(int &x : c) cin>>x;
	g.assign(n, {});
	edges.resize(m);
	for(int i=0;i<m;++i){
		int u,v,s;
		cin>>u>>v>>s;
		--u; --v;
		--s;
		g[u].push_back(s);
		g[v].push_back(s);
		edges[s] = {u,v};
	}
}

template<int N, int M, int K>
void gen(int &n, int &m, int &k, graph &g, vector<edge> &edges, vector<int> &c){
	n = N;
	m = M;
	k = K;
	g.assign(n, {});
	edges.resize(m);
	
	vector<int> s(m);
	iota(ALL(s), 1);
	shuffle(ALL(s), rnd);
	
	set<pair<int,int>> u;
	for(int i=0;i<m;++i){
		int x,y;
		do{
			x = rnd()%n;
			y = rnd()%n;
		}while(x==y || u.count({x,y}));
		u.insert({x,y});
		u.insert({y,x});
		g[x].push_back(s[i]-1);
		g[y].push_back(s[i]-1);
		edges[s[i]-1] = {x,y};
	}
	
	c.resize(n);
	for(int &x : c) x = rnd()%512 + 1;
}

ll ff =0;
vector<int> hit(const int start, const graph &g, const vector<edge> &edges){
	static int banned[MAX_N] = {0}, iter = 0;
	++iter;
	
	assert(!empty(g[start]));
	int n = size(g);
	
	vector<int> res;
	int v = start, pk = -1;
	for(;;){
		//assert(!empty(g[v]));
		//assert(is_sorted(ALL(g[v])));
		auto it = begin(g[v]);
		int h = *it;
		if(h==pk){
			++it;
			if(it==end(g[v])) h = -1;
			else h = *it;
		}
		if(h==-1) break;
		const edge&e = edges[h];
		int nx = e.from(v);
		if(banned[nx] == iter) break;
		res.push_back(h);
		banned[v] = iter;
		for(int k : g[v]){
			int to = edges[k].from(v);
			banned[to] = iter;
		}
		pk = h;
		v = nx;
	}
	
	assert(1 <= size(res));
	assert(size(res) <= 256);
	
	return res;
}

void remove_way(int v, vector<int> &w, graph &g, const vector<edge> &edges){
	for(int k : w){
		int to = edges[k].from(v);
		erase(g[v], k);
		erase(g[to], k);
		v = to;
	}
}


struct result {
	vector<int> hits, color;
	
	void print(){
		cout<<size(hits)<<endl;
		for(int v : hits) cout<<v+1<<' '; cout<<endl;
		for(int col : color) cout<<col+1<<' '; cout<<endl;
	}
	
	int evaluate(const vector<int> &cost){
		int total = 0;
		for(int v : hits) total+=cost[v];
		return total;
	}
	
	int evaluate_and_check(
		const int K,
		const graph &g, 
		const vector<edge> &edges,
		const vector<int> &cost
	){
		int n = size(g);
		for(int i=0;i<n;++i){
			assert(0<=color[i] && color[i]<K);
			for(int k : g[i]){
				int j = edges[k].from(i);
				assert(color[i]!=color[j]);
			}
		}
		
		return evaluate(cost);
	}
};


bool check_bipartite(
	const graph &g,
	const vector<edge> &edges,
	vector<int> &color
){
	const int n = size(g);
	
	fill(ALL(color),-1);
	vector<int> q(n);
	for(int i=0;i<n;++i) if(color[i]==-1){
		color[i] = 0;
		q[0] = i;
		for(int qn=1,h=0;h<qn;++h){
			const int v = q[h];
			for(int k : g[v]){
				int i = edges[k].from(v);
				if(color[i]==-1){
					color[i] = 1-color[v];
					q[qn++] = i;
				}else{
					if(color[i] == color[v]) return false;
				}
			}
		}
	}
	return true;
}

bool check_Kpartite(
	const int K,
	const graph &g,
	const vector<edge> &edges,
	vector<int> &color
){
	if(K==2) return check_bipartite(g,edges,color);
	
	const int full_ms = (1<<K) - 1;
	
	const int n = size(g);
	vector<char> possible_colors(n, full_ms);
	vector<int> uncolored_nbs(n);
	for(int i=0;i<n;++i){
		uncolored_nbs[i] = size(g[i]);
		color[i] = -1;
	}
	vector<pair<int,int>> q_init(n);
	for(int i=0;i<n;++i) q_init[i] = {K, -uncolored_nbs[i]};
	iheap<pair<int,int>> q(q_init);
	int vertices = n;
	for(int i=0;i<n;++i) if(empty(g[i])) color[i] = 0, q.remove(i), --vertices;
	
	while(vertices>0){
		int vertex = q.get_index_of_min();
		if(possible_colors[vertex]==0) return false;
		
		vector<int> cnt(K);
		for(int k : g[vertex]){
			int i = edges[k].from(vertex);
			if(color[i]==-1){
				for(int col=0;col<K;++col) if(possible_colors[vertex]>>col&1){
					if(possible_colors[i]>>col&1){
						++cnt[col];
					}
				}
			}
		}
		
		//color[vertex] = __builtin_ctz(possible_colors[vertex]);
		for(int col=0;col<K;++col) if(possible_colors[vertex]>>col&1){
			if(color[vertex] == -1 || cnt[col]<cnt[color[vertex]]) color[vertex] = col;
		}
		
		q.remove(vertex);
		for(int k : g[vertex]){
			int i = edges[k].from(vertex);
			if(color[i]==-1){
				possible_colors[i]&=full_ms^(1<<color[vertex]);
				uncolored_nbs[i]--;
				q.set_value(i, {
					__builtin_popcount(possible_colors[i]),
					-uncolored_nbs[i]
				});
			}
		}
		--vertices;
	}
	
	/*for(int i=0;i<n;++i) assert(color[i]<K && color[i]>=0);
	for(int i=0;i<n;++i) for(int k : g[i]){
		int j = edges[k].from(i);
		assert(color[i]!=color[j]);
	}*/
	
	return true;
}

template<bool dirty = false>
void do_delete_all(
	graph &g,
	const vector<edge> &edges,
	const vector<int> &cost,
	vector<int> &hits,
	const int K,
	vector<int> &color
){
	const int n = size(g);
	
	int remaining_edges = 0;
	for(int i=0;i<n;++i) remaining_edges+=size(g[i]);
	remaining_edges>>=1;
	if(remaining_edges == 0) return ;
	
	vector<vector<int>> torecalc(size(edges));
	vector<vector<int>> depends(n);
	vector<double> pay_per_edge(n);
	
	auto calc_profit = [&](const int i) -> void {
		if(empty(g[i])){
			pay_per_edge[i] = -1;
			return ;
		}
		
		auto w = hit(i,g,edges);
		
		int cnt = size(w);
		pay_per_edge[i] = ld(cost[i]) / cnt ;
		int v = i;
		for(int k : w){
			if(!dirty || dirty && v==i){
				torecalc[k].push_back(i);
				depends[i].push_back(k);
			}
			v = edges[k].from(v);
		}
		for(int k : g[v]){
			if(k!=w.back()){
				torecalc[k].push_back(i);
				depends[i].push_back(k);
				break; 
			}
		}
	};
	
	for(int i=0;i<n;++i) calc_profit(i);
	iheap<double> q(pay_per_edge);
	for(int i=0;i<n;++i) if(pay_per_edge[i]<0) q.remove(i);
	
	
	const int rem_lim = get_edges_limit(K,n);
	const int check_lim = get_edges_limit_to_check_Kpartite(K,n);
	
	for(; remaining_edges>0;){
		
		if(K>1){
			if(remaining_edges<=check_lim){
				if(check_Kpartite(K,g,edges,color)){
					cerr<<"found "<<K<<"-partite on "<<remaining_edges<<" edges"<<endl;
					return ;
				}
			}
		}
		
		if constexpr(dirty){
			if(remaining_edges < rem_lim){
				cerr<<"! switched from dirty to strict at "<<remaining_edges<<" edges"<<endl;
				do_delete_all<false>(g,edges,cost,hits,K,color);
				return ;
			}
		}
		
		const int v = q.get_index_of_min();
		if(empty(g[v])){
			q.remove(v);
			continue ;
		}
		
		auto w = hit(v,g,edges);
		hits.push_back(v);
		
		remove_way(v, w, g, edges);
		remaining_edges-=size(w);
		
		set<int> torec = {v};
		for(int k : w) torec.insert(ALL(torecalc[k]));
		for(int i : torec){
			for(int k : depends[i]) erase_unordered(torecalc[k],i);
			depends[i].clear();
		}
		for(int k : w) torecalc[k].clear();
		for(int i : torec) {
			calc_profit(i);
			if(auto val = pay_per_edge[i]; val<0) q.remove(i);
			else q.set_value(i, val);
		}
	}
}


result solve_dummy_v1(graph &g, const vector<edge> &edges, const int &K, const vector<int> &cost){
	const int n = size(g);
	
	vector<int> hits;
	vector<int> color(n);
	for(int i=0;i<n;++i) color[i] = rnd()%K;
	
	
	vector<set<int>> todo(K);
	for(int i=0;i<n;++i){
		int col = color[i];
		for(int k : g[i]){
			int j = edges[k].from(i);
			if(color[j] == col){
				todo[col].insert(k);
			}
		}
	}
	
	int rem = size(edges);
	const int rem_limit = get_edges_limit(K,n);
	
	for(;;){
		
		if(rem<rem_limit){
			do_delete_all(g,edges,cost,hits,K,color);
			break;
		}
		
		
		bool done = true;
		for(int k=0;k<K;++k) if(!empty(todo[k])) done = false;
		if(done) break;
		
		vector<int> variants;
		for(int c=0;c<K;++c) if(!empty(todo[c])){
			int k = *begin(todo[c]);
			variants.push_back(k);
		}
		
		const edge &e = edges[variants[rnd()%size(variants)]];
		
		int ci = cost[e.i], cj = cost[e.j];
		int v = (ci<cj || ci==cj && rnd()%2) ? e.i : e.j;
		
		auto w = hit(v, g, edges);
		
		if(size(w) == 1){ //minor
			auto &e = edges[w[0]];
			int to = e.from(v);
			if(cost[to] < cost[v]){
				v = to;
				w = hit(to, g, edges);
			}
		}
		
		rem-=size(w);
		for(int k : w){
			auto &e = edges[k];
			int i = e.i, j = e.j;
			if(color[i] == color[j]){
				todo[color[i]].erase(k);
			}
		}
		remove_way(v, w, g, edges);
		hits.push_back(v);
	}
	
	return {hits, color};
}

template<bool dirty = false>
result solve_delete_all(graph &g, const vector<edge> &edges, const int &K, const vector<int> &cost){
	const int n = size(g);
	
	vector<int> hits;
	vector<int> color(n);
	for(int i=0;i<n;++i) color[i] = 0;
	
	do_delete_all<dirty>(g,edges,cost,hits,K,color);
	
	return {hits, color};
}

template<auto D, bool PRINT = false>
void solve(){
	vector<edge> edges;
	graph g;
	vector<int> cost;
	
	int n,m,K;
	D(n,m,K,g,edges,cost);
	for(int i=0;i<n;++i){
		g[i].shrink_to_fit();
		sort(ALL(g[i]));
	}
	
	const auto g_backup = g;
	
	result answer;
	int best = 2e9;
	
	
	auto upd = [&](auto &res){
		int val = res.evaluate_and_check(K,g,edges,cost);
		cerr<<"--- upd? "<<val<<" ---"<<endl;
		if(best > val){
			cerr<<best<<" -> "<<val<<" ("<<res.hits.size()<<")"<<endl;
			best = val;
			answer = res;
		}
	};
	
	/*if(01){
		g = g_backup;
		auto res = solve_delete_all(g,edges,K,cost);
		upd(res);
		return ;
	}*/
	
	if(n<=1e3){
		for(int it=0;it<9;++it){
			g = g_backup;
			auto res = solve_delete_all(g,edges,K,cost);
			upd(res);
		}
	}else{
		for(int it=0;it<1;++it){
			g = g_backup;
			auto res = solve_delete_all<true>(g,edges,K,cost);
			upd(res);
		}
	}
	
	
	if(PRINT) answer.print();
	cerr<<"["<<answer.evaluate(cost)<<"]"<<endl;
}


int main(){
	//freopen("input.txt","r",stdin); 
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);//cout.precision(12);cout<<fixed;
	
	
	#ifdef BIZON
		constexpr int m = 1e5;
		constexpr int n1 = 1e3;
		constexpr int n2 = 1e4;
		//solve<gen<n1,m,1>>();		//581861
		//solve<gen<n1,m,2>>();		//543291
		//solve<gen<n1,m,3>>();		//538880
		//solve<gen<n1,m,4>>();		//534551
		//solve<gen<n2,m,1>>();		//342347
		solve<gen<n2,m,2>>();		//31006
		//solve<gen<n2,m,3>>();		//4745
		//solve<gen<n2,m,4>>();		//3198  (can be 2925 if you give me 10 seconds :D)
	#else
		solve<read,true>();
	#endif
	
	#ifdef just_for_fast_code_teleportation
		hit;
		do_delete_all;
		check_Kpartite;
	#endif
	
	cerr<<"ff = "<<ff<<endl;
	return 0;
}


int get_edges_limit(int K, int n){
	if(n==1e4){
		if(K==4) return 70000; //75000 risky
		if(K==3) return 50000;
		return 45000;
	}
	return 1e6;
}

int get_edges_limit_to_check_Kpartite(int K, int n){
	if(K==4) return n*3.7;
	if(K==3) return n*2.0;
	if(K==2) return n*0.5;
	return 0;
}
