#include<bits/stdc++.h>
#include<fstream>
#define prime 1000000007
#define pb push_back
#define mp make_pair
#define forn(i,a,b) for (int i = a; i <b; i++)
#define fornn(i,a,b) for (int i = a; i <=b; i++)
#define num 1000000000
#define ALL(v) v.begin(), v.end()
#define INF INT_MAX
typedef long long ll;
using namespace std;

#define WINPAUSE system("pause")

ll power(ll x, ll y, ll p)  
{  
    ll res = 1;     
    x = x % p;   
              
   
    if (x == 0) return 0; 
  
    while (y > 0)  
    {  
     
        if (y & 1)  
            res = (res*x) % p;  
  
      
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res;  
} 
string getString(char x) 
{ 
     
    string s(1, x); 
  
    return s;    
}
bool sortbysec(const pair<ll,ll> &a, 
              const pair<ll,ll> &b) 
{ 
    return (a.second < b.second); 
} 

bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
}
vector<vector<int>> adj;
vector<int> visited;
vector<int> color;
vector<int> sl;
int dfs(int n,int cl)
   {
       visited[n]=1;
       if(cl!=color[n])
         {
             if(color[n]==1)
                sl[n]++;
             else
             {
                 
                sl[n]--;
             }
             
         }
        for(int i=0;i<adj[n].size();i++)
           {
               if(visited[adj[n][i]]==0)
                 {
                   sl[n]+=dfs(adj[n][i],1-cl);
                 }
           }
           return sl[n];
   }

bool isSmaller(string str1, string str2) 
{ 
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
        return true; 
    if (n2 > n1) 
        return false; 
  
    for (int i=0; i<n1; i++) 
    { 
        if (str1[i] < str2[i]) 
            return true; 
        else if (str1[i] > str2[i]) 
            return false; 
    } 
    return false; 
}

ll getSum(ll n) 
{  
   ll sum = 0; 
   while (n != 0) 
   { 
       sum = sum + n % 10; 
       n = n/10; 
   } 
   return sum; 
} 



int main()
 {  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE  
 freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  freopen("log.txt", "w", stderr);
  #endif
ll T;
   cin>>T;
while(T--)
  { 
     int n,k;
     cin>>n>>k;
     string s;
     cin>>s;
     int x=0,y=0;
     vector<int> v;
     if(s[0]=='0')
      {
          forn(i,0,n)
           {
               if(s[i]=='0')
                 x++;
                 else
                 {
                     break;
                 }
                 
           }
      }
      if(s[n-1]=='0')
        {
            for(int i=n-1;i>=0;i--)
               {
                   if(s[i]=='0')
                 y++;
                 else
                 {
                     break;
                 }
               }
        }
      for(int i=x;i<n-y;i++)
        {
            if(s[i]=='0')
              {
                  int size=0,j=i;
                  for( j=i;j<n;j++)
                    {
                        if(s[j]=='0')
                          size++;
                          else
                          {
                              break;
                          }
                          
                    }
                  v.pb(size);
                  
                  i=j-1;
              }

        }
           sort(ALL(v),greater<int>());
 
        int count=n;
     if(x==n)
       {
         count=0;
       }
    else if(k==0)
      {
              k/=2;
           int temp=x+y;
           forn(i,0,v.size())
             {
                  if(k)
                    k--;
                 else
                 {
                    temp+=v[i]; 
                 }
                 
             }
             count=min(count,temp);
      }
   else if(x==0 && y==0)
       {
           k/=2;
           int temp=0;
           forn(i,0,v.size())
             {
                  if(k)
                    k--;
                 else
                 {
                    temp+=v[i]; 
                 }
                 
             }
             count=min(count,temp);
       }
    else if(x && y==0)
      {
          if(k%2)
           {
                k/=2;
           int temp=0;
           forn(i,0,v.size())
             {
                  if(k)
                    k--;
                 else
                 {
                    temp+=v[i]; 
                 }
                 
             }
                count=min(count,temp);
           }
          else
          {
              v.pb(x);
              sort(ALL(v),greater<int>());
              k/=2;
           int temp=0;
           forn(i,0,v.size())
             {
                  if(k)
                    k--;
                 else
                 {
                    temp+=v[i]; 
                 }
                 
             }
                count=min(count,temp);
          }
          
        
      }
      else if(x==0 && y)
      {
          if(k%2)
           {
                k/=2;
           int temp=0;
           forn(i,0,v.size())
             {
                  if(k)
                    k--;
                 else
                 {
                    temp+=v[i]; 
                 }
                 
             }
                count=min(count,temp);
           }
          else
          {
              v.pb(y);
              sort(ALL(v),greater<int>());
              k/=2;
           int temp=0;
           forn(i,0,v.size())
             {
                  if(k)
                    k--;
                 else
                 {
                    temp+=v[i]; 
                 }
                 
             }
                count=min(count,temp);
          }
      }
      else
      {
          if(k%2==0)
            {
                v.pb(y+x);
              sort(ALL(v),greater<int>());
              k/=2;
           int temp=0;
           forn(i,0,v.size())
             {
                  if(k)
                    k--;
                 else
                 {
                    temp+=v[i]; 
                 }
                 
             }
                count=min(count,temp);
            }
            else
            {  int m=k;
                  k/=2;
           int temp=0;
           forn(i,0,v.size())
             {
                  if(k)
                    k--;
                 else
                 {
                    temp+=v[i]; 
                 }
                 
             }
             temp+=min(x,y);
             count=min(count,temp);
                 k=m;
                v.pb(y+x);
              sort(ALL(v),greater<int>());
              k/=2;
            temp=0;
           forn(i,0,v.size())
             {
                  if(k)
                    k--;
                 else
                 {
                    temp+=v[i]; 
                 }
                 
             }
                count=min(count,temp);    
            }
            
      }
      cout<<count<<"\n";
 }
 return 0;     
}
