#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define pii                pair <int,int>
#define ff first
#define ss second

using namespace std;
namespace __gnu_pbds{
          typedef tree<int,
                       null_type,
                       less_equal<int>,
                       rb_tree_tag,
                       tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;
int main()
{
   ordered_set os  ; 
   int test ;
   cin >> test ;
   while(test--)
   {
      os.clear() ; 
      int n ;
      cin >> n ;
      std::vector< pii > pq ;
      for (int i = 0; i < n ; ++i)
      {
         int x ;
         cin >> x ;
         pq.push_back({i+1,x}) ; 
      }

      int idx = 1,ans=0 ; 
      for(auto it = pq.rbegin();it!=pq.rend();it++)
      {
         pii p = *it ;
         cout << os.size() << endl ;
         if(idx==1)
         {
            os.insert(p.ss) ; 
            idx++ ; 
            continue ; 
         }
         ans+=(os.order_of_key(p.ss+1)) ; 
         os.insert(p.ss) ; 
      }
      cout << ans << endl ;
   }

   return 0 ; 
}