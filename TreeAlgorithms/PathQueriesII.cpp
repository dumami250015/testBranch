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

int n, q, a[N], tr[2 * 4 * N], in[N], out[N], t = 0;
vector<int> g[N];

void dfs(int u, int pre) {
    in[u] = ++t;
    for (int v: g[u]) {
        if (v != pre) dfs(v, u);
    }
    out[u] = t;
}

void update(int id, int l, int r, int pos, int val) {
    if (l > pos || r < pos) return;
    else if (l == r) {
        tr[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, pos, val);
    update(id << 1 | 1, mid + 1, r, pos, val);
    tr[id] = max(tr[id << 1], tr[id << 1 | 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    else if (l >= u && r <= v) return tr[id];
    int mid = (l + r) >> 1;
    return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }   
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        update(1, 1, t, in[i], a[i]);
    }
    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;
        
    }
    return 0;
}