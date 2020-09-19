#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	
	
	
	for(int i=0;i<t; i++)
	{
	   
	    int n;
	    cin>>n;
	    
	    int k;
	    cin>>k;
	    
	    int a[n];
	    
	    for(int j=0;j<n;j++){
	        cin>>a[j];}
	    
	    int count=0;
	    
		for(int j=0;j<n;j++)
		if(a[j]%2==0)
		count++;
		
		if(k==0 && count==n)
		cout<<"NO"<<endl;
		else if(count>=k)
		cout<<"YES"<<endl;
		else 
	    cout<<"NO"<<endl;   
	}	
	return 0;
}
