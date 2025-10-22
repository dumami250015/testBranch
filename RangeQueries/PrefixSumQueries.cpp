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

int n, q, tr[4 * N];

void update(int id, int l, int r, int pos, int val) {
    if (l > pos || r < pos) return;
    else if (l == r) {
        tr[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, pos, val);
    update(id << 1 | 1, mid + 1, r, pos, val);
    
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(1, 1, n, i, x);
    }
    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) update(1, 1, n, a, b);
        else cout << get(1, 1, n, a, b) << "\n";
    }
    return 0;
}