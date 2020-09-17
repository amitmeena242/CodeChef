#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln "\n"
#define pb push_back
#define pll pair<ll,ll>
#define ppll pair<ll,pll>
#define vll vector<ll>
#define vs vector<string>
#define vpll vector<pll>
#define vvll vector<vector<ll>>
#define vvpll vector<vpll>
#define f first
#define s second
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define Test ll T;cin>>T; while(T--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define init(x,n,v) for(ll i=0;i<=n;i++) x[i]=v;
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define pi 3.14159265358979323846
#define MOD 1000000007
#define MAX 2000000000000000000
#define MAXN 100005
void inout()
{
    fast_io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" , stdin);
        freopen("output.txt" , "w" , stdout);
    #endif
}
void solve() {
	ll h, w, m, a, b , i;
    cin >> h >> w >> m;
    vector<ll> l(h + 5, 0), r(w + 5, 0);
    map<pll, ll> t;
    for(i = 0 ; i < m ; i++){
        cin >> a >> b;
        l[a]++;
        r[b]++;
        pll p = make_pair(a, b);
        t[p]++;
    }
    ll max_l = *max_element(l.begin(), l.end());
    ll max_r = *max_element(r.begin(), r.end());
    vector<ll> ndx_l, ndx_r;
    for(i = 0 ; i < h + 1 ; i++) if (l[i] == max_l) ndx_l.push_back(i);
    for(i = 0 ; i < w + 1 ; i++) if (r[i] == max_r) ndx_r.push_back(i);
    ll ans = max_l + max_r - 1;
    for (auto x: ndx_l){
        for (auto y: ndx_r){
            pll p = make_pair(x, y);
            if (t[p]==0){
                ans = max_l + max_r;
                cout << ans << endl;
                return ;
            }
        }
    } 
    cout << ans << endl;
}
int main() {
    inout();
    //Test 
    solve();
    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
    return 0;
}
