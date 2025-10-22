#include <bits/stdc++.h>
using namespace std;

#define int long long
#define X first
#define Y second
#define ii pair<int, int>
#define iii pair<ii, int>
#define vii vector<ii>
const double eps = 0.000001;
const int oo = 1e18;
const int mod = 1e9 + 7;
const int N = 1e5 + 7;

int n, m, d[2][N], ans = oo;
vii g[2][N];
vector<iii> edge;

void dijkstra (int st, int type) {
    priority_queue<ii, vii, greater<ii>> q;
    d[type][st] = 0;
    q.push({st, d[type][st]});
    while (!q.empty()) {
        int u = q.top().X;
        int du = q.top().Y;
        q.pop();
        if (d[type][u] != du) continue;
        for (int i = 0; i < g[type][u].size(); i++) {
            int v = g[type][u][i].X;
            int dv = g[type][u][i].Y;
            if (d[type][v] > du + dv) {
                d[type][v] = du + dv;
                q.push({v, d[type][v]});
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
        g[0][u].push_back({v, c});
        g[1][v].push_back({u, c});
        edge.push_back(iii(ii(u, v), c));
    }
    memset(d, 0x5f, sizeof(d));
    dijkstra(1, 0);
    dijkstra(n, 1);
    for (iii u: edge) {
        ans = min({ans, d[0][u.X.X] + (u.Y / 2) + d[1][u.X.Y], d[0][u.X.Y] + (u.Y / 2) + d[1][u.X.X]});
    }
    // cout << d[0][1] << " " << d[1][2] << endl;
    cout << ans;
    return 0;
}