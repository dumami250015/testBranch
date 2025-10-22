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

int n, d[2][N], ans = 0;
vector<int> g[N];

void dfs(int u, int pre, int type) {
    for (int v: g[u]) {
        if (v != pre) {
            d[type][v] = d[type][u] + 1;
            dfs(v, u, type);
        }
    }
} 

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0, 0);
    int maxn = 0, st = 0;
    for (int i = 1; i <= n; i++) {
        if (d[0][i] > maxn) {
            maxn = d[0][i];
            st = i;
        }
    }
    dfs(st, 0, 1);
    for (int i = 1; i <= n; i++) {
        ans = max(ans, d[1][i]);
    }
    cout << ans;
    return 0;
}