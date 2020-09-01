#include<bits/stdc++.h>
using namespace std;
bool vis[200020];
void dfs(long long u,vector<vector<long long>>&g)
{
    vis[u]=1;
    long long x,y,i;
    for(i=0;i<g[u].size();i++)
    {
        x=g[u][i];
        if(!vis[x])
        dfs(x,g);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long t;
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        long long n,m,i,x,y,ind=-1,j,ct=0;
          cin>>n>>m;
        vector<vector<long long>>g(n);
        for(i=0;i<m;i++)
        {
            cin>>x>>y;
                g[x].push_back(y);
                g[y].push_back(x);
        }
        for(i=0;i<n;i++)
        {
            if(!vis[i])
           { dfs(i,g);
            ct++;}
        }
        cout<<ct<<"\n";
    }
   
}
