#include <iostream>
using namespace std;

int main() 
{
	// product-sum+1
	
	int t;
	cin>>t;
	for(int i=0;i<t; i++)
	{
	    int n;
	    cin>>n;
	    
	    int m;
	    cin>>m;
	    
	    int product=n*m;
	    int sum=m+n;
	    
	    cout<<product-sum+1<<endl;
	    
	}
		
	return 0;
}
