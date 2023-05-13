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
typedef tree<int ,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>os;
int ar[maxx+10],f[maxx+10] ; 
int main()
{
   debugMode();
   os sett ; 
   int n,k ;
   cin >> n >> k ;
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ;
      sett.insert(x) ; 
      ar[i+1] = x ; 
   }
   for (int i = 0; i < k ; ++i)
   {
      int x,y ;
      cin >> x >> y ; 
      if(ar[x]>ar[y])
      {
         f[x]++ ; 
      }
      else if(ar[y]>ar[x])
      {
         f[y]++ ; 
      }
   }
   for(int i=1;i<=n;i++)
   {
      if(i>1){cout << " " ; }
      int ans = sett.order_of_key(ar[i])-f[i] ; 
      cout << ans ; 
   }
   cout << endl ; 
   return 0 ;
}