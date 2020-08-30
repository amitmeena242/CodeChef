#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
        
    int t;
    cin>>t;
    
    while(t--)
    {
        int p;
        cin>>p;
        cout<<a[p-1]<<endl;;
        for(int i=p; i<=n; i++){
            int k=a[i-1];
            a[i-1]=a[i];
        }
        n--;
    }
	return 0;
}
