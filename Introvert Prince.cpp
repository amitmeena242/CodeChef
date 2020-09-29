#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define LLI long long int
#define LD long double
#define PB push_back
#define MP make_pair
#define FORi(i, a, b) for(int i = a; i < b ; ++i)
#define FORd(i, a, b) for(int i = a; i > b ; --i)

using namespace std;

int main(){
    int t,n,k,u,v;
    vector<bool> d1(2000000);
    vector<bool> d2(2000000);
    vector<int> used1_odd,used1_ev,used2_odd,used2_ev;
    LLI ans;
    cin >> t;
    while (t--){
        cin >> n >> k;
        FORi(i,0,n+n-1)
            d1[i]=d2[i]=0;
        FORi(i,0,k){
            cin >> u >> v;
            u--; v--;
            d1[u+v]=1;
            d2[u-v+n-1]=1;
        }
        ans=1ll*n*n;
        FORi(i,0,n+n-1){
            if (d1[i]){
                ans-=(i<n?i+1:n+n-1-i);
                if (i&1)
                    used1_odd.PB((i<n?i+1:n+n-1-i));
                else
                    used1_ev.PB((i<n?i+1:n+n-1-i));
            }
            if (d2[i]){
                ans-=(i<n?i+1:n+n-1-i);
                if (i&1)
                    used2_odd.PB((i<n?i+1:n+n-1-i));
                else
                    used2_ev.PB((i<n?i+1:n+n-1-i));
            }
        }
        sort(used2_odd.begin(),used2_odd.end());
        sort(used2_ev.begin(),used2_ev.end());
        FORi(i,0,used1_odd.size())
            if (n&1)
                ans+=used2_odd.end()-lower_bound(used2_odd.begin(),used2_odd.end(),n+1-used1_odd[i]);
            else
                ans+=used2_ev.end()-lower_bound(used2_ev.begin(),used2_ev.end(),n+1-used1_odd[i]);
        FORi(i,0,used1_ev.size())
            if ((n&1)==0)
                ans+=used2_odd.end()-lower_bound(used2_odd.begin(),used2_odd.end(),n+1-used1_ev[i]);
            else
                ans+=used2_ev.end()-lower_bound(used2_ev.begin(),used2_ev.end(),n+1-used1_ev[i]);
        used1_odd.clear();
        used1_ev.clear();
        used2_odd.clear();
        used2_ev.clear();
        cout << ans << endl;
    }
    return 0;
}
