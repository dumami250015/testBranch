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
const int N = 1e3 + 5;

int n, dp[N][N];
string s[N];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    if (s[1][1] == '*') {
        cout << 0;
        return 0;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j] != '*') {
                if (j - 1 >= 1) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
                if (i - 1 >= 1) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            }
        }
    }
    cout << dp[n][n];
    return 0;
}