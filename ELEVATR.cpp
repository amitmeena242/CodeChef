#include<bits/stdc++.h>

using namespace std;

using INT = long long;

#define NN 100100

int a[NN];
int dp[NN][2];
int n, m;
#define inf 0x3f3f3f3f

int solve(int s, int ds, int step, int t, int u, int m, int ST = 0) {
 if(abs(t-s) > m) return 0;
 if((t+m) % 2 != s % 2) return 0;
 if(step == inf) return 0;
 if(s <= t) {
  if(!ds) {
   int ss = (m - s - t + 2 + n - 2) / (n - 1) + 1; ss = max(ss, 1);
   if(ss % 2 == 0) ss++;
   dp[u][1^ST] = min(dp[u][1^ST], step + ss);
   ss = (m - s - n + t + 1 + n - 2) / (n - 1) + 1; ss = max(ss, 2);
   if(ss & 1) ss++;
   dp[u][0^ST] = min(dp[u][0^ST], step + ss);
  } else {
   int ss = (m - t + s + n - 2) / (n - 1); ss = max(ss, 0);
   if(ss & 1) ss++;
   dp[u][1^ST] = min(dp[u][1^ST], step + ss);
   ss = (m + s + t - n * 2 + n - 2) / (n - 1) + 1; ss = max(ss, 1);
   if(ss % 2 == 0) ss++;
   dp[u][0^ST] = min(dp[u][0^ST], step + ss);
  }
 } else {
  solve(n-s+1, 1-ds, step, n-t+1, u, m, ST^1);
 }
}

int solve() {
 int cnt = 0;
 for(int i=1; i<=m; i++) if(a[i] != -1) cnt++;
 if(cnt == 0) {
  if(m <= n) return 0;
  return (m - 2) / (n - 1);
 }
 int pre = 0;
 
 for(int i=1; i<=m; i++) if(a[i] != -1) {
  dp[i][0] = inf; dp[i][1] = inf;
  if(pre == 0) {
   if(i == 1) dp[i][0] = dp[i][1] = 0;
   else {
    for(int j=1; j<=n; j++) {
     solve(j, 0, 0, a[i], i, i - 1);
     solve(j, 1, 0, a[i], i, i - 1);
    }
   }
  } else {
   for(int j=0; j<2; j++) {
    solve(a[pre], j, dp[pre][j], a[i], i, i - pre);
   }
  }
  pre = i;
 }
// cerr << dp[7][0] << endl;
 if(a[m] == -1) {
  dp[m][1] = dp[m][0] = inf;
  for(int i=1; i<=n; i++) for(int j=0; j<2; j++) {
   solve(a[pre], j, dp[pre][j], i, m, m - pre);
  }
 }
 int ans = min(dp[m][1], dp[m][0]);
 if(ans == inf) return -1;
 return ans;
}

int main() {
#ifndef ONLINE_JUDGE
 freopen("in.in", "r", stdin);
 freopen("out.out", "w", stdout);
#endif
 int T; cin >> T;
 
 for(int ii=1; ii<=T; ii++) {
  cin >> m >> n;
  for(int i=1; i<=m; i++) scanf("%d", a+i);
  cout << solve() << endl;
 }
}
