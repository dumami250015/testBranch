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

int n, a[N], ans = 1;
map<int, int> mp;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int x;
    int l = 1;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (mp[x]) {
            ans = max(ans, i - l);
            // cout << i << " " << res << " " << mp[a[i]] << endl; 
            l = max(l, mp[x] + 1);
        }
        else ans = max(ans, i - l + 1);
        mp[x] = i;
    }
    ans = max(ans, n - l + 1);
    cout << ans;
    return 0;
}