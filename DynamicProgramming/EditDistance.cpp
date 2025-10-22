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
const int N = 5e3 + 5;

int n, m, dp[N][N];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b;
    cin >> a >> b;
    n = a.size();
    m = b.size();
    a = " " + a;
    b = " " + b;
    // dp[i][j] maximum common prefix end at i-th and j-th
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = oo;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
        }
    }
    cout << dp[n][m];
    return 0;
}