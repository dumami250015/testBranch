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

int n, q, par[N][18], h[N];
vector<int> g[N];

void dfs(int u, int pre) {
    for (int v: g[u]) {
        if (v != pre) {
            h[v] = h[u] + 1;
            par[v][0] = u;
            dfs(v, u);
        }
    }
}

void biLift() {
    for (int j = 1; j <= 17; j++) {
        for (int i = 1; i <= n; i++) {
            if (par[i][j - 1]) par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n - 1; i++) {
        int u;
        cin >> u;
        g[u].push_back(i + 1);
        g[i + 1].push_back(u);
    }
    dfs(1, 0);
    biLift();
    while (q--) {
        int x, k;
        cin >> x >> k;
        int val = log2(k) + 1;
        for (int i = val; i >= 0; i--) {
            if (k - (1 << i) >= 0) {
                x = par[x][i];
                k -= (1 << i);
            }
        }
        if (x) cout << x << "\n";
        else cout << "-1\n";
    }
    return 0;
}