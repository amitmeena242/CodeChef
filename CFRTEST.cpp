#include<iostream>
using namespace std;


int main()
{
	int t;
	cin>>t;
	
	   for(int k=0;k<t;k++)
	   {
		int n;
		cin>>n;
		int a[n];
		
		int c=0,count[101]={0};
		
		for(int i=0;i<n;i++)
		{
		cin>>a[i];
		count[a[i]]++;
		}
		
		
		for(int i=0;i<101;i++)
		{
			if(count[i]>0)
			c++;
		}
		cout<<c<<endl;		
	}
}
