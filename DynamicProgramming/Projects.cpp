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

int n, a[N], b[N], p[N], dp[N];
map<int, int> compress;;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> p[i];
        compress[a[i]];
        compress[b[i]];
    }
    int pos = 1;
    for (auto &it: compress) {
        it.Y = pos++;
    }
    vector<vii> project(pos + 5);
    for (int i = 1; i <= n; i++) {
        a[i] = compress[a[i]];
        b[i] = compress[b[i]];
        // cout << a[i] << " " << b[i] << " " << p[i] << endl;
        project[b[i]].push_back({a[i], p[i]});
    }
    for (int i = 1; i <= pos; i++) {
        if (i > 1) dp[i] = dp[i - 1];
        for (auto it: project[i]) {
            dp[i] = max(dp[i], dp[it.X - 1] + it.Y);
            // cout << dp[i] << endl;
        }
    }
    cout << dp[pos];
    return 0;
}