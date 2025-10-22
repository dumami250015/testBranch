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

int n, q, par[N][30];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> par[i][0];
    }
    for (int j = 1; j < 30; j++) {
        for (int i = 1; i <= n; i++) {
            if (par[i][j - 1]) {
                par[i][j] = par[par[i][j - 1]][j - 1];
                
            }
        }
    }
    while (q--) {
        int x, k;
        cin >> x >> k;
        for (int i = 0; i < 30; i++) {
            if (k & (1 << i)) x = par[x][i];
        }
        cout << x << "\n";
    }
    return 0;
}