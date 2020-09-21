#include <bits/stdc++.h>
using namespace std;

int V[500005], up[500005], down[500005];
int parent[500005], sizex[500005];

vector<int> X[500005], Z;
map<int, int> Y[500005];

void dfs(int x, int par)
{
    int maxx = 0;

    if (par && V[par] <= V[x])
        up[x] = up[par] + 1;
    else
        up[x] = 1;

    for (auto y : X[x])
        if (y != par)
        {
            dfs(y, x);

            if (V[y] >= V[x])
                maxx = max(maxx, down[y]);
        }
    
    down[x] = maxx + 1;
    Y[x][ V[x] ] = down[x];
}

int find_parent(int x)
{
    if (x == parent[x])
        return x;
    
    return parent[x] = find_parent(parent[x]);
}

void cleanUp1(int x, int y)
{
    Z.clear();
    auto it = Y[x].find(y);
    int target = it->second;

    while (it != Y[x].begin())
    {
        it--;

        if (it->second > target)
            break;
        
        Z.push_back(it->first);
    }

    for (auto z : Z)
        Y[x].erase(z);
}

void cleanUp2(int x, int y)
{
    auto it = Y[x].find(y);
    int target = it->second;

    it++;

    if (it == Y[x].end())
        return;
    
    if (it->second >= target)
        Y[x].erase(y);
}

void unite(int a, int b)
{
    a = find_parent(a);
    b = find_parent(b);

    if (sizex[a] < sizex[b])
        swap(a, b);
    
    parent[b] = a;
    sizex[a] += sizex[b];

    for (auto it : Y[b])
    {
        int val = it.first, len = it.second;
        
        if (Y[a].count(val))
            Y[a][val] = max(Y[a][val], len);
        else
            Y[a][val] = len;
        
        cleanUp1(a, val);
        cleanUp2(a, val);
    }

    Y[b].clear();
}

int query(int val, int x)
{
    x = find_parent(x);

    auto pr = Y[x].lower_bound(val);

    if (pr != Y[x].end())
        return pr->second;
    
    return 0;
}

int solve(int x, int par)
{
    int ans = 0, prev = -1;

    for (auto y : X[x])
        if (y != par)
        {
            ans = max(ans, solve(y, x));
            
            if (prev != -1)
                unite(prev, y);
            
            prev = y;
        }

    ans = max(ans, up[x] + (prev == -1 ? 0 : query(V[x], prev)));

    if (prev != -1)
        unite(x, prev);

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        for (int i=1; i<=n; i++)
        {
            cin >> V[i];
            X[i].clear(), Y[i].clear();

            parent[i] = i, sizex[i] = 1;
        }

        for (int i=1; i<=n-1; i++)
        {
            int u, v;
            cin >> u >> v;

            X[u].push_back(v);
            X[v].push_back(u);
        }

        dfs(1, 0);
        int ans = solve(1, 0);

        if (ans == 1)
            ans = 0;

        cout << ans << "\n";
    }

    return 0;
}
