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

int n, m, c[N];
vector<int> a[N];
bool visited[N], ok = true;

void dfs(int u, int type) {
    visited[u] = 1;
    c[u] = type;
    for (int v: a[u]) {
        if (v != u) {
            if (!visited[v]) dfs(v, type ^ 1);
            else {
                if (c[u] == c[v]) {
                    ok = false;
                    return;
                }
            }
        }
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i, 0);
        if (!ok) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << c[i] + 1 << " ";
    }
    return 0;
}