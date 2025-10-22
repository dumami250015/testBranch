#include <bits/stdc++.h>

#define int long long
#define ii pair <int, int>
#define iii pair<ii, int>
#define vii vector<ii>
#define X first
#define Y second
using namespace std;

const int oo = 1e18;
const double eps = 0.00001;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;

int n, m, sz[N], parent[N], ans = 0, maxn = 0;

int Find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v) {
    v = Find(v);
    u = Find(u);
    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    ans = n;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (Union(u, v)) {
            ans--;
            maxn = max(maxn, sz[Find(u)]);
        }
        cout << ans << " " << maxn << "\n";
    }
    return 0;
}