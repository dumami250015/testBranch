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

int n, fir[N], sec[N], ans[N];
vector<int> g[N];

void dfs(int u, int pre) {
    for (int v: g[u]) {
        if (v != pre) {
            dfs(v, u);
            if (fir[v] + 1 > fir[u]) {
                sec[u] = fir[u];
                fir[u] = fir[v] + 1;
            }
            else if (fir[v] + 1 > sec[u]) sec[u] = fir[v] + 1;
        }
    }
}

void dfsAns(int u, int pre, int prePath) {
    ans[u] = max(fir[u], prePath);
    for (int v: g[u]) {
        if (v != pre) {
            if (fir[v] + 1 == fir[u]) dfsAns(v, u, max(sec[u], prePath) + 1);
            else dfsAns(v, u, ans[u] + 1);
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
    dfs(1, 0);
    dfsAns(1, 0, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}