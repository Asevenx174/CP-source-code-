
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pii                pair <int,int>
#define ff first
#define ss second
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;

int a[200005] ; 
int main()
{
   
   int test ;
   cin >> test ;
   while(test--)
   {
      int n ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         int x ;
         cin >> x ;
         a[i] = x ;  
      }

         ordered_set s;
        int ans = 0;
        for(int i = 0; i < n; ++i){
            ans += s.size() - s.order_of_key({a[i], -1});
            s.insert({a[i], i});
        }
        cout << ans << '\n';

   }
      return 0 ;
}
