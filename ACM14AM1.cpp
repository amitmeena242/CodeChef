#include<iostream>
using namespace std;

int main() 
{
	int n,t,k,ele;
	cin>>t;
	
	for(int i=0;i<t; i++)
	{
		cin>>n;
		cin>>k;
		
		int count=0;
	
	for(int j=0;j<n;j++)
	{
		cin>>ele;
		if(ele>=k)
		count++;
	}
	cout<<count<<endl;
	}
	
	return 0;
}
