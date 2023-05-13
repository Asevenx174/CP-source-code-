#include <bits/stdc++.h>
using namespace std;

const int N = 300010;
int n;
int minp[N], prime[N], idx;
vector<pair<int, int>> vc[N * 2];
int dis[N * 2], pre[N * 2];
queue<int> q;
bool vis[N * 2];

typedef long long LL;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int maxn = *max_element(a.begin(), a.end());

    for(int i = 2; i <= maxn; i++)
    {
    	if(!minp[i]) prime[idx++] = i, minp[i] = i;
    	for(int j = 0; j < idx && prime[j] <= maxn / i; j++)
    	{
    		minp[prime[j] * i] = prime[j];
    		if(i % prime[j] == 0) break;
    	}
    }
    
    for(int i = 1; i <= n; i++)
    {
    	int x = a[i];
        cout << x << "-->" << endl ; 
    	for(int j = x; j > 1; j /= minp[j])
    	{
            cout << j << endl ;
    		vc[i].emplace_back(minp[j] + n, 0);
    		vc[minp[j] + n].emplace_back(i, 1);
    	}
    }

    memset(dis, 0x3f, sizeof dis);

    vector<int> ans;

    int s, en;
    cin >> s >> en;
    q.push(s);
    vis[s] = true;
    dis[s] = 0;

    while(q.size())
    {
    	auto t = q.front();
    	q.pop();
        vis[t] = false;

    	if(t == en)
    	{
    		ans.push_back(t);
    		while(pre[t])
    		{
    			ans.push_back(pre[t]);
                t = pre[t];
    		}

    		reverse(ans.begin(), ans.end());

    		cout << dis[en] + 1 << '\n';

    		for(auto it : ans)
    		{
    			if(it > n) continue;
    			else cout << it << " ";
    		}
            return 0;
    	}

    	
    }

    cout << -1;


	return 0;
}