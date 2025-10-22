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
const int N = 1e6 + 5;

int n, x, c, dp[N];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> x;
    for (int i = 1; i <= x; i++) {
        dp[i] = oo;
    }
    for (int i = 1; i <= n; i++) {
        cin >> c;
        for (int j = 0; j <= x - c; j++) {
            if (dp[j] != oo) {
                dp[j + c] = min(dp[j + c], dp[j] + 1);
            }
        }
    }
    if (dp[x] == oo) cout << -1;
    else cout << dp[x];
    return 0;
}