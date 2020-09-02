#include <bits/stdc++.h>
using namespace std;
#define deci(n) fixed<<setprecision(n)
#define modulo 1000000007

typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll x = n/2;
        x = (ll) sqrt(x);
        cout<<x * 2<<endl;
    }
    return 0;
}
