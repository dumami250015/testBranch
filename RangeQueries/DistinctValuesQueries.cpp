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

int n, m, s, a[N], ans = 0, res[N], cnt[N];
iii q[N];
map<int, int> mp;
vector<int> v;

bool cmp(iii a, iii b) {
    if (a.X.X / s != b.X.X / s) return a.X.X < b.X.X;
    return a.X.Y > b.X.Y;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    s = sqrt(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    int pos = 1;
    for (int it: v) {
        if (!mp[it]) mp[it] = pos++;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = mp[a[i]];
    }
    for (int i = 1; i <= m; i++) {
        cin >> q[i].X.X >> q[i].X.Y;
        q[i].Y = i;
    }
    sort (q + 1, q + m + 1, cmp);
    int l = 0, r = 0;
    for (int i = 1; i <= m; i++) {
        while (l < q[i].X.X) {
            cnt[a[l]]--;
            if (!cnt[a[l]]) ans--;
            l++;
        }
        while (l > q[i].X.X) {
            l--;
            cnt[a[l]]++;
            if (cnt[a[l]] == 1) ans++;
        }
        while (r < q[i].X.Y) {
            r++;
            cnt[a[r]]++;
            if (cnt[a[r]] == 1) ans++;
        }
        while (r > q[i].X.Y) {
            cnt[a[r]]--;
            if (!cnt[a[r]]) ans--;
            r--;
        }
        res[q[i].Y] = ans;
    }
    for (int i = 1; i <= m; i++) {
        cout << res[i] << "\n";
    }
    return 0;
}