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

int n, a[N], dp[N], tr[4 * N];
map<int, int> compress;

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
    if (l > v || r < u) return -oo;
    else if (l >= u && r <= v) return tr[id];
    int mid = (l + r) >> 1;
    return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        compress[a[i]];
    }
    int pos = 1;
    for (auto &it: compress) {
        it.Y = pos++;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = compress[a[i]];
        if (a[i] == 1) dp[i] = 1;
        else dp[i] = get(1, 1, n, 1, a[i] - 1) + 1;
        update(1, 1, n, a[i], dp[i]);
    }
    cout << tr[1];
    return 0;
}