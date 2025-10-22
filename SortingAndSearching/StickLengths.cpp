#include <bits/stdc++.h>

#define int long long
#define ii pair<int, int>
#define iii pair<ii, int>
#define vii vector<ii>
#define X first
#define Y second
using namespace std;

const int oo = 1e18;
const double eps = 0.000001;
const int mod = 1e9 + 7;
const int N = 2e5 + 7;

int n, a[N], pre[N], ans = oo;

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        ans = min(ans, a[i] * i - pre[i] - (n - i) * a[i] + pre[n] - pre[i]);
    }
    cout << ans;
    return 0;
}
