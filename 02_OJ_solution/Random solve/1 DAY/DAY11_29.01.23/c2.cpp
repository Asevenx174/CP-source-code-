#include <bits/stdc++.h>
#define fo(i, x, y) for (int i = int(x); i <= int(y); ++i)
#define fd(i, x, y) for (int i = int(x); i >= int(y); --i)
#define fi first
#define se second

using namespace std;
using u64 = unsigned long long;

void work()
{
    int n, m;
    cin >> n >> m;
    vector rec(n, vector<int>(m));
    set<u64> st;
    for (auto &p : rec)
    {
        u64 hsh = 0;
        for (auto &x : p)
        {
            cin >> x;
            hsh = hsh * (m + 1) + x;
            st.emplace(hsh);
        }
    }
    map<u64, int> len;
    fo(i, 0, n - 1)
    {
        auto &p = rec[i];
        vector<int> pos(m + 1);
        fo(j, 0, m - 1)
            pos[p[j]] = j;
        u64 hsh = 0;
        fo(j, 1, m)
        {
            hsh = hsh * (m + 1) + (pos[j] + 1);
            if (st.count(hsh))
                len[hsh] = j;
        }
    }
    fo(i, 0, n - 1)
    {
        auto &p = rec[i];
        u64 hsh = 0;
        int ans = 0;
        for (auto &x : p)
        {
            hsh = hsh * (m + 1) + x;
            if (len.count(hsh))
                ans = len[hsh];
        }
        cout << ans << " \n"[i + 1 == n];
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    #ifdef LC
    freopen("t.in", "r", stdin);
    freopen("t.out", "w", stdout);
    #endif
    int T;
    cin >> T;
    while (T--)
        work();
    return 0;
}