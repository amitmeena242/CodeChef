#include <bits/stdc++.h>
#define ll long long
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll arr[n];
    for(ll i=0;i<n;i++){
        ll x;
        cin >> x;
        arr[i]=x;
    }
    sort(arr,arr+n);
    ll arr1[n];
    ll res=0;
    for(ll i=0;i<n;i++){
        arr1[i]=arr[i]*(n-i);
        res=max(res,arr1[i]);
    }
    cout << res << endl;
}    
