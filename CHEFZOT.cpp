#include <iostream>
using namespace std;

int main() 
{
	// your code goes here
	int n;
	cin>>n;
	
	int a[n];
	for(int i=0;i<n;i++)
	{
	   cin>>a[i]; 
	}
	
	int maxlen=-1;
	int len=0;
	for(int j=0;j<n;j++)
    {
//Check if the first element is 0
        if(a[j]!=0)
            len++;
            
        else if(len>maxlen)
            {
                maxlen=len;
                len=0;
            }
            else 
            len=0;
    }
    
    if(len>maxlen)
    maxlen=len;
    cout<<maxlen<<endl;  
	return 0;
}
