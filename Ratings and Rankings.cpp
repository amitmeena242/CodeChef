#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
 ll t;
 cin >> t;
 while(t--)
 {
  ll n,m,i,j;
  cin >> n >> m;
  ll initial[n];
  for(i=0;i<n;i++)
   cin >> initial[i];
   
  ll change[n][m],rating[n][m];
  for(i=0;i<n;i++)
  {
   for(j=0;j<m;j++)
    cin >> change[i][j];
  }
  ll rank[n][m];
  for(i=0;i<n;i++)
  {
   rating[i][0]=initial[i]+change[i][0];
   for(j=1;j<m;j++)
    rating[i][j]=rating[i][j-1]+change[i][j];
  }
  for(j=0;j<m;j++)
  {
   vector<pair<ll,ll> >v;
   for(i=0;i<n;i++)
    v.push_back({rating[i][j],i});
   
   sort(v.rbegin(),v.rend());
   rank[v[0].second][j]=1;
   ll cnt=1;
   for(i=1;i<v.size();i++)
   {
    cnt++;
    if(v[i].first==v[i-1].first)
     rank[v[i].second][j]=rank[v[i-1].second][j];
    else
     rank[v[i].second][j]=cnt; 
   }
  }
  ll ans=0;
  for(i=0;i<n;i++)
  {
   set<pair<ll,ll> >hi,be;
   map<ll,ll>h,b;
   for(j=0;j<m;j++)
   {
    if(h[rating[i][j]]==0)
     hi.insert({rating[i][j],j});
    if(b[rank[i][j]]==0)
     be.insert({rank[i][j],j}); 
    h[rating[i][j]]++;
    b[rank[i][j]]++;
   }
   //cout<<(*hi.rbegin()).second<<" "<<(*be.begin()).second<<"\n";
   if((*hi.rbegin()).second==(*be.begin()).second)
    ans++;
   
  }
  cout<<n-ans<<"\n";
 }
}
