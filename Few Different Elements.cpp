#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  auto check = [](int x, int y, int z) -> bool {
    int cnt = (x == -1) + (y == -1) + (z == -1);
    if (cnt >= 2) return true;
    if (cnt == 0) return x == y or x == z or y == z;
    assert(cnt == 1);
    if (z == -1) return x == y;
    return true;
  };

  auto enc = [&](int a, int b, int c) -> int {
    int res{}, cur{};
    res |= (a == -1) << cur++;
    res |= (b == -1) << cur++;
    res |= (a == b) << cur++;
    res |= (a == c) << cur++;
    res |= (b == c) << cur++;
    return res;
  };

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& e : a) cin >> e;
    if (n < 3) {
      cout << "0\n";
      continue;
    }
    assert(n >= 3);
    map<array<int, 2>, int> dp;
    dp[{-1, -1}] = 0;
    for (int i = 0; i < n; ++i) {
      int cur = 0x3f3f3f3f;
      for (auto [key, val] : dp) cur = min(cur, val);
      map<int, decltype(begin(dp))> mp;
      for (auto it = begin(dp); it != end(dp);) {
        auto [x, y] = it->first;
        int id = enc(x, y, a[i]);
        if (it->second > cur + 1) {
          it = dp.erase(it);
        } else if (not mp.count(id)) {
          mp[id] = it;
          ++it;
        } else {
          // mp[id]->second = min(mp[id]->second, it->second);
          if (it->second > cur)
            it = dp.erase(it);
          else
            ++it;
        }
      }

      map<array<int, 2>, int> ndp;
      for (auto [key, val] : dp) {
        auto [x, y] = key;
        vector<int> zs{x, y, a[i], -1};
        for (int z : zs) {
          if (not check(x, y, z)) continue;
          auto nkey = array{y, z};
          int nval = val + (z != a[i]);
          if (not ndp.count(nkey) or ndp[nkey] > nval) ndp[nkey] = nval;
        }
      }
      swap(dp, ndp);
    }

    int ans = 0x3f3f3f3f;
    for (auto [key, val] : dp) ans = min(ans, val);
    cout << ans << '\n';
  }
}
