#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	lli t;
	cin>>t;
	lli d=t,k=0;
	vector<lli>h(d);
	while(t--){
	    lli n,c=0;
	    cin>>n;
	    vector<lli>v(n);
	    map<lli,lli>m;
	    for(lli i=0; i<n; i++){
	        cin>>v[i];
	        m[v[i]]++;
	        if(m[v[i]]==1 && v[i]!=0)
	            c++;
	        }
	        h[k++]=c;
	    }
	    for(lli i=0; i<d; i++)
	        cout<<h[i]<<"\n";
	return 0;
}
