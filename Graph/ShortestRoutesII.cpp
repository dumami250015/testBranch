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
const int N = 505;

int n, m, q, d[N][N];
vii g[N];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> q;
    int u, v, w;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = oo;
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        d[u][v] = d[v][u] = min(d[u][v], w);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) d[i][j] = 0;
                else d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    while (q--) {
        cin >> u >> v;
        if (d[u][v] >= oo) cout << "-1\n";
        else cout << d[u][v] << "\n";
    }
    return 0;
}