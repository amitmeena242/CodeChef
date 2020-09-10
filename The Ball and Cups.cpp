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
	    
	    int c;
	    cin>>c;
	    
	    int q;
	    cin>>q;
	    
	    while(q--)
	    {
	        int l;
	        int r;
	        cin>>l;
	        cin>>r;
	        
	        if(c>=l && c<=r)
	            c=l+r-c;
	    }
	    cout<<c<<endl;
	}
	
	return 0;
}
