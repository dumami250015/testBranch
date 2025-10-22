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

int n, q, tr[2 * 4 * N], down[2 * 4 * N], a[N], in[N], out[N], t = 0;
vector<int> g[N];

void dfs(int u, int pre) {
    in[u] = ++t;
    for (int v: g[u]) {
        if (v != pre) dfs(v, u);
    }
    out[u] = t;
}

void lazy(int id) {
    int v = down[id];
    tr[id << 1] += v;
    tr[id << 1 | 1] += v;
    down[id << 1] += v;
    down[id << 1 | 1] += v;
    down[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;
    else if (l >= u && r <= v) {
        tr[id] += val;
        down[id] += val;
        return;
    }
    lazy(id);
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);
    tr[id] = tr[id << 1] + tr[id << 1 | 1];
}

int get(int id, int l, int r, int pos) {
    if (l > pos || r < pos) return 0;
    else if (l == r) return tr[id];
    lazy(id);
    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, pos) + get(id << 1 | 1, mid + 1, r, pos);
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
        update(1, 1, t, in[i], out[i], a[i]);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s, x;
            cin >> s >> x;
            update(1, 1, t, in[s], out[s], x - a[s]);
            a[s] = x;
        }
        else {
            int s;
            cin >> s;
            cout << get(1, 1, t, in[s]) << "\n";
        }
    }
    return 0;
}