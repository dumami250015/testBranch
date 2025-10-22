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
const int N = 505;

int n, dp[N][62630];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int limit = n * (n + 1) / 2;
    if (limit % 2) {
        cout << 0;
        return 0;
    }
    limit /= 2;
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= limit; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - i >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % mod;
        }
    }
    cout << dp[n - 1][limit];
    return 0;
}