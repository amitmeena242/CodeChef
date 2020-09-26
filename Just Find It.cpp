#include <bits/stdc++.h>
//#define long long ll
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> arr(n);
        vector<long long> pre(n+1,0),pre_even(n+1,0),pre_odd(n+1,0);
        map<long long,vector<long long>> mp;
        for(long long  i=0;i<n;i++){
            cin>>arr[i];
            pre[i+1]=arr[i]+pre[i];
            //mp[arr[i]]++;
            if(arr[i]%2==0){
                pre_even[i+1]=pre_even[i]+1;
                pre_odd[i+1]=pre_odd[i];
            }else{
                pre_odd[i+1]=pre_odd[i]+1;
                pre_even[i+1]=pre_even[i];
            }
            mp[arr[i]].push_back(i);
            
        }
    //    for(int i=0;i<=n;i++) cout<<pre_even[i]<<" ";
        long long mx=0;
       for(auto it=mp.begin();it!=mp.end();it++){
           if(it->second.size()>1){
               long long sz=it->second.size();
               long long i=0;
               long long j=i+1;
        if(it->first%2){
    
               while(i<sz && j<sz){
                    if((pre_odd[it->second[j]+1]-pre_odd[it->second[i]]-2)%2){
                        mx=max(mx,pre[it->second[j]+1]-pre[it->second[i]]-2*arr[it->second[i]]);
                    }
                    i++;
                    j++;
               }
        }else{
            
            while(i<sz && j<sz){
                    if((pre_even[it->second[j]+1]-pre_even[it->second[i]]-2)%2==0){
                        mx=max(mx,pre[it->second[j]+1]-pre[it->second[i]]-2*arr[it->second[i]]);
                    }
                    i++;
                    j++;
               }
        }
           }
       }
        cout<<mx<<"\n";
    }
    return 0;
}
