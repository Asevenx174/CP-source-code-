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
ll ar[maxx+10],n,br[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n,f=0 ;
      cin >> n ;
      for(int i=1;i<=n;i++)
      {
         cin >> ar[i] ; 
         if(i>1 && min(ar[i],ar[i-1])>zz ){f=1;}
      }
      if(f==qq)
      {
         cout << "NO" << endl ; continue ;  
      }
      ll k = 0 ; 
      ll idx = 1 ; 
      while(idx<=n)
      {
         ll sum = ar[idx] ; 
         while(idx+1<=n && ( min(ar[idx],ar[idx+1])>=zz || max(ar[idx],ar[idx+1])<zz  ) )
         {
            idx++ ; 
            sum+=ar[idx] ; 
         }
         br[++k] = sum ; 
         //cout << k << " " << sum << endl ;
         idx++ ; 
      }
      idx = br[1]>zz ? 1 : 2 ;
      while(idx+2LL<=k)
      {
         ll b = min(br[idx+2],br[idx]) ; 
         ll c = max(br[idx+2],br[idx]) ;
         ll a = br[idx+1] ;
         if(a+b>zz){f=1;}  
         idx+=2 ;
      }
      if(f==qq)
      {
         cout << "NO" << endl ; 
      }
      else
      {
         cout << "YES" << endl ;
      }
   }
   return 0 ;
}