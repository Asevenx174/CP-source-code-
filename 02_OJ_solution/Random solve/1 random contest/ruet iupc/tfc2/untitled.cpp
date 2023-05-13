#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pb           push_back
#define mp           make_pair
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define PI 3.14159265 /// tan inverse = atan(value)*(180/PI)

#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

#define SL(a)              scanf("%I64d",&a)
#define SLL(a,b)           scanf("%I64d %I64d",&a,&b)
#define PL(x) printf("%I64d\n",(x))
#define PLL(x,y) printf("%I64d %I64d\n",x,y)

#define S(a)              scanf("%d",&a)
#define SS(a,b)           scanf("%d %d",&a,&b)
#define P(x) printf("%d\n",(x))
#define PP(x,y) printf("%d %d\n",x,y)

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
bool com(const pii &a,const pii &b)
{
    if(a.ff==b.ff)
    {
       return a.ss < b.ss ;
    }
    else
    {
       return a.ff < b.ff ; 
    }
}
ll mr[maxx+5],fr[maxx+5] ;
int main()
{
   debugMode() ;
   map < int ,int > mm,mf ; 
   set < int > sm,sf ; 
   ll n ;
   cin >> n ; 
   for (int i = 0; i < n ; ++i)
   {
      ll x,y ;
      cin >> x >> y ;
      mr[i+1] = x ; 
      fr[i+1] = y ; 
      sm.insert(x) ; 
      sf.insert(y) ; 
   }
   ll idx = 1 ; 
   for(auto x : sm )
   {
      mm[x] = idx++ ; 
   }
   idx = 1 ; 
   for(auto x : sf )
   {
      mf[x] = idx++ ; 
   }
   std::vector < pii > pp ;
   for (int i = 1 ; i <= n ; ++i)
   {
      ll x = mr[i] ; 
      ll y = fr[i] ; 
      pp.push_back({ mm[x], mf[y] });
   }
   sort(pp.begin(),pp.end(),com) ; 
   ordered_set oset ;
   ll ans = 0 ; 
   for(auto p : pp )
   {
      ll y = -p.ss ; 
      if(oset.empty())
      {
          oset.insert(y) ; 
      }
      else
      {
          ll add = oset.order_of_key(y) ;
          ans+=add ; 
          oset.insert(y) ;  
      }
   }
   cout << ans << endl ;
   return 0 ;
}