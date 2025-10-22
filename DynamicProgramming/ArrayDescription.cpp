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
const int N = 1e5 + 5;

int n, m, a[N], dp[N][105];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (a[1]) dp[1][a[1]] = 1;
    else {
        for (int i = 1; i <= m; i++) {
            dp[1][i] = 1;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (!a[i]) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                if (j - 1 >= 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                if (j + 1 <= m) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
            }
        }
        else {
            dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i]]) % mod;
            if (a[i] - 1 >= 1) dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] - 1]) % mod;
            if (a[i] + 1 <= m) dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][a[i] + 1]) % mod;
        }
    }
    if (a[n]) cout << dp[n][a[n]];
    else {
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            ans = (ans + dp[n][i]) % mod;
        }
        cout << ans;
    }
    return 0;
}