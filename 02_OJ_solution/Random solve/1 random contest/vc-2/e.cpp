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

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}

ll ar[maxx+10],br[maxx+10] ; 
ll pre[100] ; 
void calco(ll p)
{
   ll idx = 0 ;
   while(1)
   {
      ll temp = (qq << idx ) ; 
      if(temp>p){break;}
      if( ( temp&p) )
      {
         pre[idx]++ ; 
      }
      idx++ ; 
   } 
}
ll fun(ll idx)
{
   ll pos = idx ; 
   ll ans = 0 ; 
   std::vector < ll > pq (100,0) ;
   for (int i = 0; i < 60 ; ++i)
   {
      pq[i] = pre[i] ;  
   }
   ll p = ar[pos] ; 
   idx = 0 ;
   while(1)
   {
      ll temp = (qq << idx ) ; 
      if(temp>p){break;}
      if( ( temp&p) )
      {
         pq[idx]-- ; 
      }
      idx++ ; 
   } 
   p = br[pos] ; 
   idx = 0 ;
   while(1)
   {
      ll temp = (qq << idx ) ; 
      if(temp>p){break;}
      if( ( temp&p) )
      {
         pq[idx]++ ; 
      }
      idx++ ; 
   } 
   idx = 0 ; 
   while(idx<60)
   {
      ll temp = qq << idx ; 
      if(pq[idx]>0)
      {
         ans+=temp ; 
      }
      idx++ ; 
   }
   return ans ; 
}
int main()
{
   debugMode();
   ll n,k,x,best=0,idx=0 ;
   cin >> n >> k >> x ;
   for (int i = 0; i < n ; ++i)
   {
      ll y ;
      cin >> y ; 
      ar[i] = y ;  
      calco(y) ; 
      ll temp = y ; 
      ll co = k ; 
      while(co--)
      {
         temp = temp*x ; 
      } 
      br[i] = temp ; 
   }
   ll ans = 0  ; 
   for (int i = 0; i < n ; ++i)
   {
      ll temp = fun(i) ; 
      ans = max(ans,temp) ; 
   }
   cout << ans << endl ;
   return 0 ;
}