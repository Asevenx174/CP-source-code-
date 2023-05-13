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
const ll maxx = 2e5+10,mod=1e9+7,imax=1e9,qq=1,zz=0;

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
os s ; 
ll ar[maxx+10],n,k ; 
bool valid(ll g)
{
   ll temp = k ; 
   for(int i=1;i<n;i++)
   {
      ll a=ar[i],b=ar[i+1] ; 
      ll p=2,q=2;  
      if(ar[i]<g)
      {
         if(temp>0)
         {a = imax ; 
         s.erase(s.find(ar[i])) ; 
         s.insert(a) ; 
         temp-- ;
         p = 1 ; 
         }
         else
         {
            p = 0 ;
            continue ; 
         } 
      }
      if(ar[i+1]<g)
      {
         if(temp>0)
         {b = imax ; 
         s.erase(s.find(ar[i+1])) ; 
         s.insert(b) ;
         temp-- ;
         q = 1 ; 
         }
         else
         {
            q = 0 ;  
         }
      }
      auto it = o_set.find_by_order(temp) ;
      
      if(*it<=g){return true ;}
   }
   return false ; 
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      cin >> n >> k ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
         s.insert(ar[i+1]) ; 
      }
      ll l=1,r=mod ; 
      while(l<=r)
      {
         ll mid = (l+r)/2LL ;
         if(valid(mid))
         {

         }
         else
         {

         }
      }
   }
   return 0 ;
}