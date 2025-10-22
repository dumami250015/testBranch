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

struct node {
    int maxSub, maxL, maxR, sum;
    node operator + (node v) {
        return {
            max({maxSub, v.maxSub, maxR + v.maxL}),
            max(sum + v.maxL, maxL),
            max(maxR + v.sum, v.maxR),
            sum + v.sum
        };
    }
};

int n, m;
node tr[4 * N];

void update(int id, int l, int r, int pos, int val) {
    if (l > pos || r < pos) return;
    else if (l == r) {
        tr[id] = {max(0ll, val), max(0ll, val), max(0ll, val), val};
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, pos, val);
    update(id << 1 | 1, mid + 1, r, pos, val);
    tr[id] = tr[id << 1] + tr[id << 1 | 1];
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(1, 1, n, i, x);
    }
    while (m--) {
        int k, x;
        cin >> k >> x;
        update(1, 1, n, k, x);
        cout << tr[1].maxSub << "\n";
    }
    return 0;
}