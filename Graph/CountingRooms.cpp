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

int n, m, ans = 0;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
char a[N][N];
bool visited[N][N];

bool inside(int x, int y) {
    if (x >= 1 && x <= n && y >= 1 && y <= m) return true;
    return false;
}

void bfs(int x, int y) {
    visited[x][y] = 1;
    queue<ii> q;
    q.push({x, y});
    while(!q.empty()) {
        ii top = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x1 = top.X + dx[i];
            int y1 = top.Y + dy[i];
            if (inside(x1, y1) && !visited[x1][y1] && a[x1][y1] == '.') {
                visited[x1][y1] = 1;
                q.push({x1, y1});
            }
        }
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '.' && !visited[i][j]) {
                ans++;
                bfs(i, j);
            }
        }
    }
    cout << ans;
    return 0;
}