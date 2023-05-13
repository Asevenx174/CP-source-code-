#include<bits/stdc++.h>
#define int long long
//#define double long double

using namespace std;

using pii = pair<int, int>;
using pll = pair<long long, long long>;

int arr[1 << 20];

signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  set<int> se;
  for(int i = 0; i < (1 << 20); i++)
    se.insert(i);

  fill(arr, arr + (1 << 20), -1);

  int q; cin >> q;
  while(q--) {
    int t, x; cin >> t >> x;

    if (t == 1) {
      auto ite = se.lower_bound(x % (1 << 20));
      if (ite == se.end())
        ite = se.begin();
      arr[*ite] = x;
      se.erase(ite);
    } else {
      cout << arr[x % (1 << 20)] << '\n';
    }
  }

  return 0;
}
