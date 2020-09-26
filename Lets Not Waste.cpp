#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define vt vector
#define pb push_back
#define pii pair<int,int>
#define mii map<int,int>
#define mod 1000000007
#define endl "\n"
#define FOR(n) for(int i=0;i<n;i++)
#define FOR1(x) for(auto i:x)
#define ff first
#define ss second
#define all(c) c.begin(),c.end()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void read(int &a) { cin>>a; }
void read(int &a, int &b) { cin>>a>>b; }
void read(int &a, int &b, int &c) { cin>>a>>b>>c; }
void read(vt<int> &v) { FOR(v.size()) cin>>v[i]; }
void write(string s="\n") { cout<<s<<endl; }
void write(int a) { cout<<a<<endl; }
void write(int a, int b) { cout<<a<<" "<<b<<endl; }
void write(vt<int> v) { FOR(v.size()) cout<<v[i]<<" "; cout<<endl; }

void solve()
{
    //write your code here..
    int a,b;
    read(a,b);
    if(a%2 || b>a)
    {
        cout<<"-1";
    }
    else
    {
        int c=0;
        while(a!=b && a>=0 && b>=0)
        {
            a-=2;
            b-=1;
            c++;
        }
        if(a==b)
        {
        write(a/2,c);
        cout<<"Rs. "<<110*a + 120*c; 
        }
        else
        cout<<"-1";
    }
}

int32_t main()
{
    fastio;
	int t=1;
	//read(t);
	while(t--)
	{
	    solve();
	}
	return 0;
}
