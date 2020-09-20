#include <iostream>
#include<math.h>
#include<iomanip>

using namespace std;

int main()
{
    int t;
	cin>>t;
	
	for(int i=0;i<t;i++)
	{
		int b,c;
		double s,v;
		
		cin>>b;
		cin>>c;
		
		s=b-sqrt(b*b-24*c);
		s/=12;
		v=s*s*s+c*s/2-s*s*b/4;
		cout<<fixed<<setprecision(2)<<v<< endl;
	}
	return 0;
}
