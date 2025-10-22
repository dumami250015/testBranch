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

int n, m, d[N][N];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
ii trace[N][N];
char a[N][N];
bool visited[N][N];

bool inside(int x, int y) {
    if (x >= 1 && x <= n && y >= 1 && y <= m) return true;
    return false;
}

void bfs(int x, int y) {
    queue<ii> q;
    q.push({x, y});
    visited[x][y] = 1;
    d[x][y] = 0;
    trace[x][y] = {0, 0};
    while(!q.empty()) {
        ii top = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x1 = top.X + dx[i];
            int y1 = top.Y + dy[i];
            if (inside(x1, y1) && !visited[x1][y1] && a[x1][y1] != '#') {
                visited[x1][y1] = 1;
                d[x1][y1] = d[top.X][top.Y] + 1;
                trace[x1][y1] = {top.X, top.Y};
                if (a[x1][y1] == 'B') return;
                q.push({x1, y1});
            }
        }
    }
}

void back(int x, int y) {
    if (x == 0 && y == 0) return;
    back(trace[x][y].X, trace[x][y].Y);
    if (x - trace[x][y].X == 0 && y - trace[x][y].Y == 1) cout << "R";
    if (x - trace[x][y].X == 0 && y - trace[x][y].Y == -1) cout << "L";
    if (x - trace[x][y].X == 1 && y - trace[x][y].Y == 0) cout << "D";
    if (x - trace[x][y].X == -1 && y - trace[x][y].Y == 0) cout << "U";
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int ax, ay, bx, by;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                ax = i;
                ay = j;
            }
            if (a[i][j] == 'B') {
                bx = i;
                by = j;
            }
        }
    }
    bfs(ax, ay);
    if (!d[bx][by]) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << "\n";
    cout << d[bx][by] << "\n";
    back(bx, by);
    return 0;
}