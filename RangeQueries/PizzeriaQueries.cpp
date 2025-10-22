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

int n, q, a[N], tr[2][4 * N];

void update(int id, int l, int r, int pos, int val, int type) {
    if (l > pos || r < pos) return;
    else if (l == r) {
        tr[type][id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, pos, val, type);
    update(id << 1 | 1, mid + 1, r, pos, val, type);
    tr[type][id] = min(tr[type][id << 1], tr[type][id << 1 | 1]);
}

int get(int id, int l, int r, int u, int v, int type) {
    if (l > v || r < u) return oo;
    else if (l >= u && r <= v) return tr[type][id];
    int mid = (l + r) >> 1;
    return min(get(id << 1, l, mid, u, v, type), get(id << 1 | 1, mid + 1, r, u, v, type));
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(1, 1, n, i, a[i] - i, 0);
        update(1, 1, n, i, a[i] + i, 1);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, x;
            cin >> k >> x;
            update(1, 1, n, k, x - k, 0);
            update(1, 1, n, k, x + k, 1);
        }
        else {
            int k;
            cin >> k;
            cout << min(get(1, 1, n, 1, k, 0) + k, get(1, 1, n, k, n, 1) - k) << "\n";
        }
    }
    return 0;
}