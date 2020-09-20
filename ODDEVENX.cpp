#include <iostream>
using namespace std;

int main() 
{
	int n;
	cin>>n;
	
	int oc=0;
	int ec=0;
	
	int a[n];
	
	for(int j=0;j<n;j++)
	{
	    cin>>a[j];
	}
	
	for(int i=0;i<n; i++)
	{
	    if(a[i]%2!=0)
	    oc+=1;
	    else
	    ec+=1;
	}
	cout<<abs(ec-oc)<<endl;	
	return 0;
}
