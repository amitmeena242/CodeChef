#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define ii insert
#define ld long double
#define sz(x) (int)x.size()
#define all(v) v.begin(),v.end()
#define ppb pop_back
#define shiva ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define input freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);
#define TT int testcases;cin>>testcases;while(testcases--)
#define MOD 1000003
#define ll long long
#define endl "\n"
using namespace std;
#define N 10005
void solve()
{
	int n;
	cin>>n;
	
	int a[n];
	int c=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<0)
		c++;
		if(a[i]>=0)
		{
			ans+=a[i];
		}
	}
	
	if(c==n)
	{
		cout<<0<<endl<<0<<endl;
		return ;
	}
	
	cout<<ans<<endl;
	vector<int>v;
	
	int i=0;
	int j=n-1;
	
	while(i<j)
	{
		if(a[i]>=0)
		{
		i++;
		continue;
		
		}
		if(a[j]<0)
		{
			j--;
			continue;
		}
		if(a[i]<0 and a[j]>=0 )
		{
			v.pb(i+1);
			v.pb(j+1);
			i++;
			j--;
			continue;
		}
	}
	
	sort(all(v));
	
	cout<<v.size()<<" ";
	for(int i=0;i<v.size();i++)
	cout<<v[i]<<" ";
	cout<<endl;	
}
signed main()
{
  	TT	
	solve();
	return 0;
}
