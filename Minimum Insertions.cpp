#include <bits/stdc++.h>
//Fast io
#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//Class shorthands
#define ll long long
#define db long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define mi map<int,int>
#define mii map<pii,int>
//Function Shorthands
#define fi first
#define se second
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define mp make_pair
#define po pop_back
#define eb emplace_back
//Code Shorthands
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repe(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(int i=b;i>=a;i--)
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()
//Constants
#define hell 1000000007
#define PI acos(-1.0)
using namespace std;
int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a%b);
}
void solve(){
	int n;
	cin>>n;
	int a[n];
	rep(i,0,n) cin>>a[i];
	vi c;
	for(int i=0;i<n;i++){
		if(gcd(a[i], a[(i+1)%n]) == 1) c.pb(i);
	}
	vi d;
	if(c.empty()) {
		d.pb(n);
		for(int i=2;i<=n;i++){
			int cur = n/(i-1);
			if(n%(i-1)+(i-1)>=i) cur++;
			cout<<cur<<" ";
		}
		cout<<endl;
	}
	else {
		for(int i=0;i<c.size()-1;i++){
			d.pb(c[i+1]-c[i]-1);
		}
		d.pb(n-(c.back()+1-c[0]));
		
		sort(all(d));
		vi ind(n+1);
		int cur = 0;
		int las = 0;
		for(int i=0;i<d.size();i++){
			if(d[i]>=cur){
				while(cur<=d[i]){
					ind[cur] = i;
					cur++;
				}
			}
		}
		while(cur<=n) ind[cur++] = d.size();
		for(int i=2;i<n+1;i++){
			int cur = 0;
			for(int j = i-1;j<=n;j+=(i-1)){
				int in = ind[j];
				int aa = (d.size()-in);
				cur+=aa;
			}
			cout<<cur<<" ";
		}
		cout<<endl;
	}
}

int main(){
	io;
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}
