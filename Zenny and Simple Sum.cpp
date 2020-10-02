#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define mod 1000000007
bool prime[1000001]={false};
void sieve()
{
	prime[0]=false;
	prime[1]=false;
	int j;
	for(j=2;j<=1000000;j++)
	{
		prime[j]=true;
	}
	for(j=2;j<=1000;j++)
	{
		if(prime[j])
		{
			for(int k=2;j*k<=1000000;k++)
			  prime[j*k]=false;
		}
	}
}
bool isprime(int x)
{
	if(x<=0)
	  return false;
    return prime[x];
}
void build(int tree[],int arr[],int start,int end,int index)
{
	if(start==end)
	{
		tree[index]=arr[start];
		return ;
	}
	else
	{
		int mid=(start+end)/2;
		build(tree,arr,start,mid,2*index);
		build(tree,arr,mid+1,end,2*index+1);
		tree[index]=tree[2*index]+tree[2*index+1];
	}
}
void update(int tree[],int lazy[],int start,int end,int left,int right,int val,int index)
{
	if(left>end||start>right)
	  return ;
    if(start>=left&&end<=right)
    {
		tree[index]+=val;
		if(start!=end)
		{
			lazy[2*index]+=val;
			lazy[2*index+1]+=val;
		}
		return ;
	}
	else
	{
		int mid=(start+end)/2;
		update(tree,lazy,start,mid,left,right,val,2*index);
		update(tree,lazy,mid+1,end,left,right,val,2*index+1);
		tree[index]=tree[2*index]+tree[2*index+1];
	}
}
int sum_query(int tree[],int lazy[],int start,int end,int left,int right,int index)
{	
	if(left>end||start>right)
	   return 0;
	if(start>=left&&end<=right)
	  return tree[index];
	else
	{
		int mid=(start+end)/2;
		int x=sum_query(tree,lazy,start,mid,left,right,2*index);
		int y=sum_query(tree,lazy,mid+1,end,left,right,2*index+1);
		return x+y;
	}
}
int dfs(int src,vector<int> adj[],int p,int size[])
{
	int here=1;
	for(int x:adj[src])
	{
		if(x!=p)
		{
			here+=dfs(x,adj,src,size);
		}
	}
	size[src]=here;
	return here;
}
void dfs(int src,vector<int> adj[],int p,int mp[],int &val)
{
	val++;
	mp[src]=val;
	for(int x:adj[src])
	{
		if(x!=p)
		   dfs(x,adj,src,mp,val);
	}
}
int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		set<int> st1,st2;
		int j;
		int n;
		cin>>n;
		for(j=0;j<n;j++)
		{
			int x;
			cin>>x;
			if(x>=0)
			  st1.insert(x);
			else
			  st2.insert(x);
		}
		int val1=0,val2=0;
		for(int x:st1)
		  val1+=x;
		for(int x:st2)
		  val2+=x;
		cout<<val1<<" "<<val2<<endl;
	}
}
