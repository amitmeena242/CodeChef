#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        long long int n;
        cin>>n;
        
        long long int a[n];
        
        for(int j=0;j<n;j++){
          cin>>a[j];
        }
        cout<<(n*(n-1))/2<<endl;
    }
    return 0;
}
