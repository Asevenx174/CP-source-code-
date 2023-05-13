#include <bits/stdc++.h>
using namespace std;

constexpr int infinity = 1000000000;

deque<int> path;
vector<vector<int>> dist, edges, previous;
vector<tuple<int, int, int>> bad;
queue<int> Q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    edges.assign(1 + n, vector<int>());
    while (m--) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    while (k--) {
        int a, b, c;
        cin >> a >> b >> c;
        bad.push_back(make_tuple(a, b, c));
    }
    sort(bad.begin(), bad.end());
    dist.assign(1 + n, vector<int>(1 + n, infinity));
    previous.assign(1 + n, vector<int>(1 + n, 0));
    dist[1][0] = 0;
    Q.push(0);
    Q.push(1);
    while (!Q.empty()) {
        int b = Q.front();
        Q.pop();
        int c = Q.front();
        Q.pop();
        for (int d: edges[c]) {
            if (binary_search(bad.begin(), bad.end(), make_tuple(b, c, d))) {
                continue;
            }
            if (dist[c][b] + 1 < dist[d][c]) {
                dist[d][c] = dist[c][b] + 1;
                previous[d][c] = b;
                Q.push(c);
                Q.push(d);
            }
        }
    }
    int d = n;
    int c = 1;
    for (int i = 0; i <= n; ++i) {
        if (dist[d][i] < dist[d][c]) {
            c = i;
        }
    }
    if (dist[d][c] == infinity) {
        cout << -1 << endl;
        return 0;
    }
    cout << dist[d][c] << endl;
    path.push_front(d);
    path.push_front(c);
    while (previous[d][c] > 0) {
        int b = previous[d][c];
        d = c;
        c = b;
        path.push_front(b);
    }
    for (int i: path) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
