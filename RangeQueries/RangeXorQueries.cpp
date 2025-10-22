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

int n, q, pre[N];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (i == 1) pre[i] = x;
        else pre[i] = pre[i - 1] ^ x;
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (pre[a - 1] ^ pre[b]) << "\n";
    }
    return 0;
}