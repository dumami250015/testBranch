#include <bits/stdc++.h>
using namespace std;

#define int long long
#define X first
#define Y second
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int N = 2505;
int n, m, d[N];
vii g[N];

void dijkstra (int st) {
    priority_queue<ii, vii, greater<ii>> q;
    d[st] = 0;
    q.push({st, d[st]});
    while (!q.empty()) {
        int u = q.top().X;
        int du = q.top().Y;
        q.pop();
        if (d[u] < du) continue;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].X;
            int dv = g[u][i].Y;
            if (d[v] > du + dv) {
                d[v] = du + dv;
                q.push({v, d[v]});
            }
        }
    }
}

main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, -c});
        g[v].push_back({u, -c});
    }
    memset(d, 0x5f, sizeof(d));
    dijkstra(1);
    cout << -d[n];
    return 0;
}