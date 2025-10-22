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
const int N = 2e5 + 5;

int n, m, par[N][18], h[N], dp[N], ans[N];
vector<ii> g[N];

void dfs(int u, int pre) {
    for (ii v: g[u]) {
        if (v.X != pre) {
            h[v.X] = h[u] + 1;
            par[v.X][0] = u;
            dfs(v.X, u);
        }
    }
}

void dfsAns(int u, int pre) {
    for (ii v: g[u]) {
        if (v.X != pre) {
            dfsAns(v.X, u);
            dp[u] += dp[v.X];
        }
    }
}

void biLift() {
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (par[i][j - 1]) par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}

int LCA(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    int x = log2(h[u]);
    for (int j = x; j >= 0; j--) {
        if (h[u] - (1 << j) >= h[v]) u = par[u][j];
    }
    if (u == v) return u;
    for (int j = x; j >= 0; j--) {
        if (par[u][j] != par[v][j]) {
            u = par[u][j];
            v = par[v][j];
        }
    }
    return par[u][0];
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    dfs(1, 0);
    biLift();
    while (m--) {
        int u, v;
        cin >> u >> v;
        dp[u]++;
        dp[v]++;
        dp[LCA(u, v)]--;
        dp[par[LCA(u, v)][0]]--;
    }
    dfsAns(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    return 0;
}