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

int n, m, a[N], tr[4 * N];

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

void get(int id, int l, int r, int val) {
    if (l == r) {
        if (tr[id] >= val) {
            cout << l << " ";
            tr[id] -= val;
        }
        else cout << "0 "; 
        return;
    }
    else {
        int mid = (l + r) >> 1;
        if (tr[id << 1] >= val) get(id << 1, l, mid, val);
        else get(id << 1 | 1, mid + 1, r, val);
    }
    tr[id] = max(tr[id << 1], tr[id << 1 | 1]);
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(1, 1, n, i, a[i]);
    }
    while (m--) {
        int x;
        cin >> x;
        get(1, 1, n, x);
    }
    return 0;
}