#include <bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define lop ios; ll t; cin>>t; while(t--)
#define pb push_back
#define vi vector<ll>
#define vivi vector<vector<ll>>
#define vipa vector<pair<ll,ll>>
#define F first
#define S second
#define M 1000000007
#define kl "\n"
typedef long long ll;
ll lcm(ll x, ll y){ll k=x*y; k/=(__gcd(x,y)); return k;}
ll power(ll x,ll y){ ll r= 1;x = x % M;if(x==0) return 0; while(y>0) {if(y&1) r=(r*x)%M; y=y>>1; x=(x*x)%M;} return r;}

ll valid(vector<long double> &v,long double mid,long double xx){
     long double c=v[0]+mid;
        for(ll i=1;i<v.size();i++)
        {
            if(v[i]>=c)
            {
                c=v[i]+mid;
                continue;
            }
            if(v[i]+xx<c)
            {
                return 0;
            }
            c=c+mid;
        }
        return 1;
}

void solve()
{
    ll n,d;
    cin>>n>>d;
    long double xx=d*1.0;
    vector<long double>v;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        v.pb(x*1.0);
    }
    sort(v.begin(),v.end());
    long double l=0.0;
    long double r=10000000000.0;
    long double ans;
    while(r-l>0.0000001){
        long double mid=l+(r-l)/2.0;
        if(valid(v,mid,xx)) l=mid,ans=mid;
        else r=mid;
    }
    cout<<fixed<<setprecision(6)<<ans<<kl;
}
int main()
{
    lop
    solve();
 return 0;
}
