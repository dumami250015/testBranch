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

int n, m, ans = 0;
vector<int> a[N], g[N];
vector<ii> edge;
bool visited[N];

void bfs(int st) {
    visited[st] = 1;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: a[u]) {
            if (!visited[v]) {
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
    int pre = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bfs(i);
            ans++;
            if (pre) edge.push_back({pre, i});
            pre = i;
        }
    }
    ans--;
    cout << ans << "\n";
    for (ii it: edge) {
        cout << it.X << " " << it.Y << "\n";
    }
    return 0;
}