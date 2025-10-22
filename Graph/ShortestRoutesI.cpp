// #include <bits/stdc++.h>

// #define int long long
// #define ii pair <int, int>
// #define iii pair<ii, int>
// #define vii vector<ii>
// #define X first
// #define Y second
// using namespace std;

// const int oo = 1e18;
// const double eps = 0.00001;
// const int mod = 1e9 + 7;
// const int N = 1e5 + 5;

// int n, m, d[N];
// vii g[N];

// void dijkstra(int st) {
//     priority_queue<ii, vii, greater<ii>> q;
//     d[st] = 0;
//     q.push({st, 0});
//     while(!q.empty()) {
//         int u = q.top().X;
//         int du = q.top().Y;
//         q.pop();
//         if (du > d[u]) continue;
//         for (ii edge: g[u]) {
//             int v = edge.X;
//             int dv = edge.Y;
//             if (d[v] > du + dv) {
//                 d[v] = du + dv;
//                 q.push({v, d[v]});
//             }
//         }
//     }
// }

// main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     cin >> n >> m;
//     int u, v, w;
//     for (int i = 1; i <= m; i++) {
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});
//     }
//     for (int i = 1; i <= n; i++) {
//         d[i] = oo;
//     }
//     dijkstra(1);
//     for (int i = 1; i <= n; i++) {
//         cout << d[i] << " ";
//     }
//     return 0;
// }

// #include <bits/stdc++.h>

// using namespace std;
// typedef long long ll;
// const int maxN = 1e5;

// struct Edge { int v; ll w; };
// struct Node {
//     int id; ll dist;
//     friend bool operator<(const Node &a, const Node &b){
//         return a.dist > b.dist;
//     }
// };

// int N, M, a, b;
// ll dist[maxN+1], c;
// vector<Edge> G[maxN+1];
// priority_queue<Node> Q;

// int main(){
//     scanf("%d %d", &N, &M);
//     for(int i = 0; i < M; i++){
//         scanf("%d %d %lld", &a, &b, &c);
//         G[a].push_back({b, c});
//     }

//     memset(dist, 0x3f, sizeof(dist));
//     dist[1] = 0;
//     Q.push({1, 0});
//     while(!Q.empty()){
//         ll d = Q.top().dist;
//         int u = Q.top().id;
//         Q.pop();

//         if(d > dist[u]) continue;

//         for(Edge e : G[u]){
//             if(dist[e.v] > d+e.w){
//                 dist[e.v] = d+e.w;
//                 Q.push({e.v, d+e.w});
//             }
//         }
//     }

//     for(int i = 1; i <= N; i++)
//         printf("%lld%c", dist[i], (" \n")[i==N]);
// }

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define X first
#define Y second
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int N = 1e5 + 7;
int n, m, d[N];
vii g[N];

void dijkstra (int st) {
    priority_queue<ii, vii, greater<ii>> q;
    d[st] = 0;
    q.push({st, d[st]});
    while (!q.empty()) {
        int u = q.top().X;
        int du = q.top().Y;
        q.pop();
        if (d[u] != du) continue;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].X;
            int dv = g[u][i].Y;
            if (d[v] > du + dv) {
                d[v] = du + dv;
                q.push({v, d[v]});
            }
        }
    }
}

main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
    }
    memset(d, 0x5f, sizeof(d));
    dijkstra(1);
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    return 0;
}