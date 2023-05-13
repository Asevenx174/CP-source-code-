#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using myset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n ; 
//typedef tree<int ,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>os;
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      os sett ; 
      cin >> n ; 
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
      }
      ll ans = 0 ; 
      for(ll i=n;i>0;i--)
      {
         if(ar[i]<i)
         {
            ll sub = sett.order_of_key( i+1 );
            ll len = sett.size() ; 
            //cout << i << " " <<  ar[i] << " " << (len-sub) << endl ; 
            ans+=(len-sub) ; 
            sett.insert(ar[i]) ; 
         }
      }
      cout << ans << endl ;
   }
   return 0 ;
}