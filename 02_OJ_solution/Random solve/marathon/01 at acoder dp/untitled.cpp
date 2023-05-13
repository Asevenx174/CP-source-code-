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

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 3e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll h[maxx+5],n,req1=0,req2=0; 
bool valid(ll d)
{
   ll h2 = d/2LL ;
   ll h1 = d-h2 ; 
   ll r1 = req1 ; 
   ll r2 = req2 ; 
  
   ll sub1 = min(r1,h1) ; 
   r1-=sub1 ; 
   h1-=sub1 ; 

   ll sub2 = min(r2,h2) ; 
   r2-=sub2 ; 
   h2-=sub2 ;
   
   if(r2>0)
   {
      ll add = h1/2 ; 
      add = min(add,r2) ; 
      r2-=add ; 
      h1-=(add*2) ;  
   }

   if(max(r1,r2)==0){return true ;}
   return false ; 
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      req2 = 0 ; 
      req1 = 0 ; 
      ll best=0 ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> h[i+1] ; 
         best = max(best,h[i+1]) ; 
      }
      ll r1=1,r2=0;
      for(int i=1;i<=n;i++)
      {
         ll x = best-h[i] ;
         req2+=(x/2LL) ; 
         req1+=(x%2LL) ;
         x = best+1-h[i] ; 
         r2+=(x/2LL) ; 
         r1+=(x%2LL) ;
      }

      ll l=0,r=1e18,ans=0; 
      while(l<=r)
      {
         ll m = (l+r)/2LL ; 
         if(valid(m))
         {
            ans = m ; 
            r = m-1 ; 
         }
         else
         {
            l = m+1 ; 
         }
      }
      

      l=0,r=1e18 ;
      ll temp ; 
      req1=r1 ; 
      req2=r2 ;  
      while(l<=r)
      {
         ll m = (l+r)/2LL ; 
         if(valid(m))
         {
            temp = m ; 
            r = m-1 ; 
         }
         else
         {
            l = m+1 ; 
         }
      }
      ans = min(ans,temp) ; 
      cout << ans << endl ;
   }
   return 0 ;
}