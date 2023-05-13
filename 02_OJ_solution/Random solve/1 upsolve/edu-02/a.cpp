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
const ll maxx = 100+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll pr[maxx+10],n,k ; 
bool calco(ll a,ll b,ll c,ll d)
{
   ll x = a*d ; 
   ll y = c*b ; 
   if(x>y){return false;}
   return true ; 
}
bool valid(ll add)
{
   ll p = add+pr[1] ; 
   for(int i=2;i<=n;i++)
   {
      ll x = pr[i] ; 
      if(!calco(x,p,k,100LL))
      {
         return false ; 
      }
      p+=x ; 
   }
   return true ; 
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
         cin >> pr[i+1] ; 
      }
      ll l=0,r=1e11+10,ans=0 ;
      while(l<=r)
      {
         ll m = (l+r)/2LL ;
         if(valid(m))
         {
            ans = m ; 
            r = m-1LL ;  
         }
         else
         {
            l = m+1LL ; 
         }
      } 
      cout << ans << endl ;
   }
   return 0 ;
}