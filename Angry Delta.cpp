#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i,a[n];
        int s=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]%2==0)
            s+=a[i];
        }
        cout<<s<<endl;
    }
    
    return 0;
}
