#include <iostream>
using namespace std;
 
int main()
{
    
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        int n,m,a,b;
        cin>>n;
        cin>>m;
        
        for(int j=0; j<m; j++)
        {
            cin>>a>>b;
        }
        
        if(n%2==0 && 2*m<=n)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
