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

int n, m, d[N], trace[N];
bool visited[N];
vector<int> a[N];

void back(int u) {
    if (u == 0) return;
    back(trace[u]);
    cout << u << " ";
}

void bfs(int st) {
    visited[st] = 1;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: a[u]) {
            if (!visited[v]) {
                d[v] = d[u] + 1;
                trace[v] = u;
                visited[v] = 1;
                q.push(v);
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
    bfs(1);
    if (!d[n]) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << d[n] + 1 << "\n";
    back(n);
    return 0;
}