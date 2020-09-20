#include<bits/stdc++.h>
using namespace std;
int main()
{   int t,n,k;
    cin>>t;
    while(t--)
    {   cin>>n>>k;
        int t[n],d[n],x=0,flag=1;
        for(int i=0;i<n;i++)
           cin>>t[i]>>d[i];
        int s=0;
        int cost=0,diff=0,f=0;
        
        diff=t[0]-k;
        if(diff<0)
        {   for(int i=0;i<n;i++)
            {   s+=t[i];
                if(s>k && f==0)
                f=1;
                if(f==2)
                cost+=t[i]*d[i];
                if(f==1)
                {   cost+=(s-k)*d[i];
                    f=2;
                }
            }
            cout<<cost<<endl;
            continue;
        }
        
        if(diff==0)
        {   cost=0;
            for(int i=1;i<n;i++)
            cost+=d[i]*t[i];
        }
        else if(diff>0)
        {   cost+=diff*d[0];
            for(int i=1;i<n;i++)
            cost+=d[i]*t[i];
        }
        cout<<cost<<endl;
    }
    return 0;
}
            
