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
 
int n, q, par[N][30], p[2][N][30], h[N];
vector<int> g[N], ed[2][N];
bool visited[2][N];
 
void dfs(int u, int pre) {
    for (int v: g[u]) {
        if (v != pre) {
            h[v] = h[u] + 1;
            par[v][0] = u;
            dfs(v, u);
        }
    }
}
 
void dfsEd(int u, int pre, int type) {
    visited[type][u] = true;
    for (int v: ed[type][u]) {
        if (v != pre) {
            p[type][v][0] = u;
            dfsEd(v, u, type);
        }
    }
}
 
int LCA(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    for (int i = log2(h[u]); i >= 0; i--) {
        if (h[u] - (1 << i) >= h[v]) {
            u = par[u][i];                
        }
    }
    if (u == v) return u;
    for (int i = log2(h[u]); i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
 
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
        ed[0][i].push_back(x);
        ed[1][x].push_back(i);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        if (!visited[0][i]) dfsEd(i, p[0][i][0], 0);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[1][i]) dfsEd(i, p[1][i][0], 1);
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (par[i][j - 1]) par[i][j] = par[par[i][j - 1]][j - 1];
            if (p[0][i][j - 1]) p[0][i][j] = p[0][p[0][i][j - 1]][j - 1];
            if (p[1][i][j - 1]) p[1][i][j] = p[1][p[1][i][j - 1]][j - 1];
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        int lca = LCA(u, v);
        int lu = h[u] - h[lca];
        int lv = h[v] - h[lca];
        for (int i = 0; i <= log2(lu); i++) {
            if (lu & (1 << i)) u = p[1][u][i];
        }
        if (lv) {
            for (int i = 0; i <= log2(lv); i++) {
                if (lv & (1 << i)) v = p[0][v][i];
            }
        }
        if (u != v) {
            cout << -1 << "\n";
            continue;
        }
        cout << lu + lv << "\n";
    }
    return 0;
}