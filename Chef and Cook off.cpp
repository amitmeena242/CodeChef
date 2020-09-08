#include <iostream>
using namespace std;

int main()
{
	
	int n;
	cin>>n;

	for(int i=0;i<n; i++)
	{
	   
	    int s1,s2,s3,s4,s5;
	    cin>>s1>>s2>>s3>>s4>>s5;
	    int sum=s1+s2+s3+s4+s5;
	    
	    if(sum==0)
	    cout<<"Beginner"<<endl;              
	    
	    else if(sum==1)      
	    cout<<"Junior Developer"<<endl;      
	    
	    else if(sum==2)      
	    cout<<"Middle Developer"<<endl;     
	    
	    else if(sum==3)
	    cout<<"Senior Developer"<<endl;      
	    
	    else if(sum==4)
	     cout<<"Hacker"<<endl;                
	   else
	   cout<<"Jeff Dean"<<endl;       
	        
	    }
	   
	
	return 0;
}
