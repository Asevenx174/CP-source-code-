#include<bits/stdc++.h>
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
ll v[maxx+10],n ;
ll ans[maxx+10] ; 
bool valid(ll t)
{
   ll p = 0 ; 
   for(int i=1;i<=n;i++)
   {
      p+=t ; 
      if(v[i]>p){ return false ; }
      p-=v[i] ; 
   }
   return true ; 
}
ll calco()
{
   ll l=1,r=1e9+10,t=0 ; 
   while(l<=r)
   {
      ll mid = (l+r)/2LL ;
      if(valid(mid))
      {
         t = mid ; 
         r = mid-1 ; 
      }
      else
      {
         l = mid+1 ; 
      }
   }
   return t ; 
}
int main()
{
   debugMode();
   map < int ,int > pq ; 
   std::vector < ll > k ;
   cin >> n ;
   ll sum = 0 ; 
   for(int i=1;i<=n;i++)
   {
      cin >> v[i] ; 
      sum+=v[i] ; 
   }
   ll q ;
   cin >> q ;
   while(q--)
   {
      ll x ;
      cin >> x ;
      k.push_back(x) ; 
   }
   ll t = calco() ; 
   set < int > s ; 
   pq[t] = n ; 
   s.insert(t) ; 
   for(int i=n;i>1;i--)
   {
      ll need = sum-(t*(i-1)) ; 
      ll temp = t ; 
      if(need>0)
      {
         ll add = need/(i-1) ; 
         if(add*(i-1)<need)
         {
            add++ ; 
         }
         temp+=add ; 
      }
      s.insert(temp) ; 
      pq[ temp ] = i-1 ; 
   }
   int gap = 0 ; 
   for(auto x : k )
   { 
      if(x<t)
      {
         cout << "-1" << endl ; continue ; 
      }
      auto it = s.upper_bound(x) ; 
      it-- ; 
      cout << pq[*it] << endl ;
   }
   return 0 ;
}