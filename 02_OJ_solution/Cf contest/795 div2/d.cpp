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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll calco(ll n,ll add)
{
   ll l = n/2 ; 
   ll r = n-(l*2)+add ; 
   //cout << l << " " << r << endl ;
   ll a = (l*l*2) ; 
   ll idx = 0 ;
   if(r>0 && l>0)
   {
      r-- ; 
      //cout << l << " " << idx << endl ;
      a+=(l*4+idx*2*2) ; 
      idx++ ; 
      l-- ; 
   }
   while(r>1 && l>0)
   {
      r-=2 ;
      //cout << l << " ? " << idx << endl ;
      ll temp =  2*(l*4+idx*2*2) ;
      a+=temp ; 
      l--;
      idx++ ; 
   }
   if(r>0 && l>0)
   {
       //cout << l << " " << idx << endl ;
       a+=(l*4+idx*2*2) ;
   }
   return a ; 
}
ll valid(ll n,ll g)
{
      ll a=1,b=n ; 

      while(a<=b)
      {
         ll min = (a+b)/2 ; 
         ll temp = calco() ; 
      }

      if(ans>=g){return true ; }
      return false ; 
}
int main()
{
   debugMode();
   
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll g ;
      cin >> g ; 
      ll l=0,r=maxx,ans=0 ; 
      while(l<=r)
      {
         ll mid = (l+r)/2LL ;
         if(valid(mid,g))
         {
            ans = mid ; 
            r = mid-1 ; 
         }
         else
         {
            l = mid+1 ; 
         }
      }
      cout << ans << endl ;
   }
   return 0 ;
}