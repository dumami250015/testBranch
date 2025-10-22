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
const int N = 25;

int n, x, w[N];
ii dp[1 << N];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int mask = 1; mask < (1 << n); mask++) {
        dp[mask] = ii(21, 0);
    }
    dp[0] = ii(1, 0);
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 1; i <= n; i++) {
            if ((mask >> (i - 1)) & 1) {
                int rides = dp[mask ^ (1 << (i - 1))].X;
                int weight = dp[mask ^ (1 << (i - 1))].Y;
                if (weight + w[i] > x) {
                    rides++;
                    weight = min(weight, w[i]);
                }
                else weight += w[i];
                if (rides < dp[mask].X) dp[mask] = ii(rides, weight);
                else if (rides == dp[mask].X) dp[mask] = ii(rides, min(weight, dp[mask].Y));
            }
        }
    }
    cout << dp[(1 << n) - 1].X;
    return 0;
}