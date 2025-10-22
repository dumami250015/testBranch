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

int n, x, h[1005], s[1005], dp[N];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= h[i]; j--) {
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << dp[x];
    return 0;
}