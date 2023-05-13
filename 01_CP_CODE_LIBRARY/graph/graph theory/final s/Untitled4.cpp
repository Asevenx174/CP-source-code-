#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair
#define ff first
#define ss second
const int inf = 0x3f3f3f3f;

const int N = 5000+7;
int d[N][2];
bool back[N];
bool vis[N];
int min_back[N];
vector<int> g[N], c[N];

void dijkstra(int n) {
	for(int i=1; i<=n; ++i) {
		d[i][0] = inf, d[i][1] = inf;
		vis[i] = false, back[i] = false;
		min_back[i] = inf;
		for(int &w : c[i]) min_back[i] = min(min_back[i], w+w);
	}

	priority_queue< pii > pq;
	pq.push(mp(0, 1));
	d[1][0] = 0;

	while(!pq.empty()) {
		auto top = pq.top();
		pq.pop();

		int u = top.ss, wc = -top.ff;
		if(vis[u]) {
			// visited twice, take this in second best
			d[u][1] = min(d[u][1], wc);
		}
		vis[u] = true;

		for(int i=0; i<(int) g[u].size(); ++i) {
			int temp = wc + c[u][i];
			int v = g[u][i];
			// shortest path
			if(d[v][0] > temp) {
				d[v][0] = temp;
				pq.push(mp(-temp, v));
			}
			// if not, try to update the second best
			else if(d[v][1] > temp and temp != d[v][0]) {
				d[v][1] = temp;
				pq.push(mp(-temp, v));
			}
		}

		// from u, choose a random node v. Travel u-v-u, with min cost
		if(!back[u]) {
			pq.push(mp(-(wc+min_back[u]), u));
			back[u] = true;
		}
	}
}

int main() {
	int t, tc=0;
	scanf("%d", &t);

	while(t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i=1; i<=n; ++i) g[i].clear(), c[i].clear();
		while(m--) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			g[u].push_back(v);
			c[u].push_back(w);
			g[v].push_back(u);
			c[v].push_back(w);
		}

		dijkstra(n);
		int res = d[n][1];
		printf("Case %d: %d\n", ++tc, res);
	}

	return 0;
}
