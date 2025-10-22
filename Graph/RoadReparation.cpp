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

struct edge {
    int u, v, c;
};

bool cmp(edge a, edge b) {
    return a.c < b.c;
}

int n, m, sz[N], parent[N], cnt = 0, ans = 0;
vector<edge> ed;

int Find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);
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
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        ed.push_back({u, v, c});
    }
    for (int i = 1; i <= n; i++) {
        sz[i] = 1;
        parent[i] = i;
    }
    sort(ed.begin(), ed.end(), cmp);
    for (edge ed1: ed) {
        if (Union(ed1.u, ed1.v)) {
            cnt++;
            ans += ed1.c;
        }
        if (cnt == n - 1) break;
    }
    if (cnt == n - 1) cout << ans;
    else cout << "IMPOSSIBLE";
    return 0;
}