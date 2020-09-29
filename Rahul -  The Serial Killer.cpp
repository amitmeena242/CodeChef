#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
#define MOD 1000000007
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define all(a) a.begin(),a.end()
#define ld long double
#define ll long long int

using namespace std;

int main()
{
	ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        map<ll,ll> mp;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            mp[a[i]]++;
        }

        auto comp =  [](pair<ll,ll> p1,pair<ll,ll>p2) {return p1.second < p2.second;}; 
        priority_queue<pair<ll,ll> , vector<pair<ll,ll>> , decltype(comp)> pq(comp);
        
        for(auto c:mp)
        {
            pair<ll,ll> p = {c.first,c.second};
            pq.push(p);
        }
        
        ll count=0;
        while(pq.size()>1)
        {
            pair<ll,ll> p1 = pq.top();
            pq.pop();
            pair<ll,ll> p2 = pq.top();
            pq.pop();
            ll val1=p1.second;
            ll val2=p2.second;
            val1--;
            val2--;
            count+=1;
            if(val1!=0)
                pq.push({p1.first,val1});
            if(val2!=0)
                pq.push({p2.first,val2});
        }
        
        if(pq.size()==1)
        {
            pair<ll,ll> p = pq.top();
            count+=p.second;
        }
        cout<<count<<endl;
    }
    
	return 0;
}
