#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define ar array<int,2>
#define inf 1000000000000000000 
int mod=1e9+7;
int min(int a,int b){return (a<b)?a:b;}
int max(int a,int b){return (a>b)?a:b;}
int fp(int a,int b){if(b==0) return 1;int x=fp(a,b/2);x=(x*x)%mod;if(b&1) x=(x*a)%mod;return x;}


const int N=1e6+5;
char ch[N];

struct node
{
  int ct;
  int link[26];
  node()
  {
    for(int i=0;i<26;i++)
      link[i]=-1;
    ct=-1;
  }
};
int sz=1;
node bit[N];
void insert(int id,string &s,int pos,int val)
{
  if(pos==-1)
  {
    bit[id].ct=val;
    //cout<<id<<" "<<val<<endl;
    return ;
  }

  int l=bit[id].link[s[pos]-'a'];
  
  if(l==-1)
  {
    l=++sz;
    bit[id].link[s[pos]-'a']=l;
  }
  //cout<<id<<":"<<bit[id].link[s[pos]-'a']<<" "<<s[pos]<<endl;
  insert(l,s,pos-1,val);
}
vector<int> ans;
void get(int id,int pos)
{
  //cout<<id<<endl;
  if(bit[id].ct!=-1)
    ans.push_back(bit[id].ct);
  if(pos==0)
    return ;

  int l=bit[id].link[ch[pos]-'a'];
  //cout<<id<<" "<<l<<" "<<ch[pos]<<endl;
  if(l!=-1)
  {
    get(l,pos-1);
  }
}

void solve()
{
  int n;
  cin>>n;
  string s[n+1];
  for(int i=1;i<=n;i++)
  {
    cin>>s[i];
    insert(1,s[i],s[i].size()-1,(i+1)%2);
  }   
  int q;
  cin>>q;
  for(int i=1;i<=q;i++)
  {
    cin>>ch[i];
    get(1,i);
  }
  for(auto i:ans)
    cout<<i;
  cout<<endl;
}

signed main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 srand(time(0));
 int t;
 t=1;
 for(int i=1;i<=t;i++)
 {
   solve();
 }
}
