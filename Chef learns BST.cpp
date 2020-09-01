#include <bits/stdc++.h> 
#include <boost/math/common_factor.hpp> 
#define ll long long
#define endl "\n"

using namespace std;

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n],i;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int flag=0;
        sort(a,a+n);
        for(i=0;i<n-1;i++)
        {
            if(a[i]==a[i+1])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        cout<<"No"<<endl;
        else
        cout<<"Yes"<<endl;
    }
	return 0; 
}
