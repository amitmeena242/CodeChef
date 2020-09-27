#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define sint int32_t
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long int

int t , n;
int ok = 0;
int arr[101];
int invcount = 0;
ordered_set s;

int power(int x , int y) {
    int res = 1;

    while(y) {
        if(y & 1ll) {
            res *= x;
        }
        x *= x;
        y >>= 1ll;
    }
    return res;
}

int cnt(int n , vector <int> &v) {
    if(!n) {
        return 0;
    }
    invcount = 0;

    s.clear();

    int curKey;
    s.insert(v[0]);

    for(int i = 1 ; i < n ; i++) {
        s.insert(v[i]);
        curKey = s.order_of_key(v[i] + 1);
        invcount += (s.size() - curKey);
    }

    int temp = invcount;
    return temp;
}

void solve(vector <int> &a , vector <int> &b) {
    int cntb = cnt(b.size() , b);
    int cnta = cnt(a.size() , a);

    if(cnta == cntb) {
        ok = 1;
    }
}

int32_t main() {
    cin >> t;

    for(int i = 0 ; i < t ; i ++) {
        cin >> n;
        ok = 0;
        memset(arr , 0 , sizeof(arr));

        for(int i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }

        vector <int> b;
        vector <int> a;

        for(int j = 0 ; j <= (power(2 , n)) - 1 ; j++) {

            a.clear();
            b.clear();

            for(int i = 0 ; i < n ; i++) {
                if(power(2 , i) & j) {
                    a.push_back(arr[i]);
                }
                else {
                    b.push_back(arr[i]);
                }
            }

            solve(a , b);

            if(ok) {
                break;
            }
        }

        if(!ok) {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
}
