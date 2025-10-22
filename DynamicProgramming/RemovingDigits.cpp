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

int n, dp[N];

bool check(int num, int digit) {
    bool ok = false;
    while (num) {
        if (num % 10 == digit) {
            ok = true;
            break;
        }
        num /= 10;
    }
    return ok;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = oo;
    }
    for (int i = n; i >= 0; i--) {
        for (int j = 1; j <= 9; j++) {
            if (i - j >= 0) {
                if (check(i, j)) {
                    dp[i - j] = min(dp[i - j], dp[i] + 1);
                }
            }
        }
    }
    cout << dp[0];
    return 0;
}