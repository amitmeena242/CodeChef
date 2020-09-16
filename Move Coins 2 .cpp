#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < n; i++)
#define v(a, n) vector<int> a(n, 0)
#define s(a, n) vector<string> a(n, "")
#define lb(v, x) lower_bound(v.begin(), v.end(), x)
#define ub(v, x) upper_bound(v.begin(), v.end(), x)
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define ll long long
#define mod 1000000007

ll power(ll x, ll int y, ll p)  
{  
    ll res = 1;    
  
    x = x % p; 
   
    if (x == 0) return 0; 
  
    while (y > 0)  
    {  
         
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1;  
        x = (x*x) % p;  
    }  
    return res;  
} 


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> g(n,vector<int>());
        vector<pair<int,int>> a(n-1,{0,0});
        FOR(i,n-1)
        {
            cin>>a[i].first>>a[i].second;
            g[a[i].first-1].pb(a[i].second-1);
            g[a[i].second-1].pb(a[i].first-1);
        }
        vector<vector<int>> bf(n,vector<int>(n,-1));
        FOR(i,n)
        {
            vector<bool> vis(n,false);
            queue<int> q;
            q.push(i);
            vis[i] = true;
            int level = 0;
            while(!q.empty())
            {
                int size = q.size();
            
                while(size--)
                {
                    int k = q.front();
                    if(k!=i)
                    {
                        bf[i][k] = level;
                    }
                    
                        for(int j=0;j<g[k].size();j++)
                        {
                            if(vis[g[k][j]]==false)
                            {
                                vis[g[k][j]] = true;
                            q.push(g[k][j]);
                            }
                        }
                    
                    q.pop();

                }
                level++;
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     FOR(j,n)
        //     {
        //         cout<<bf[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        ll nimsum = 0;
        v(b,n);
        FOR(i,n)
        {
            cin>>b[i];
        }
         ll ans = 0;  
        FOR(i,n)
        {
            nimsum = 0;
            FOR(j,n)
            {
                if(i!=j && b[j]%2!=0)
                {
                    nimsum^= bf[i][j];
                }
            }

            if(nimsum==0)
            {
               // cout<<i+1<<" ";
                ans = (ans%mod+power(2,i+1,mod))%mod;
            }
            
        }
        cout<<ans<<"\n";

    }
}
