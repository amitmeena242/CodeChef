#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    if(a < b)
        return gcd(b,a);
    else if(b == 0)
        return a;
    else
        return gcd(b,a%b);
}

int main()
{
	int t;
	cin>>t;
	vector<ll> res(t);
	for(int i = 0; i < t; i++)
	{
	    ll n,m;
	    cin>>n>>m;
	    
	    ll ans = (n*m)/gcd(n,m);
	    res[i] = ans;
	}
	
	for(int i = 0; i < t; i++)
    	cout<<res[i]<<endl;
	return 0;
}
