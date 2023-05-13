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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int main()
{
   debugMode();
   int n,k ;
   string s ;
   cin >> n >> k >> s ; 
   map < char ,int > f ; 
   for(auto c : s )
   {
      f[c]++ ; 
   }
   int best = 0 ; 
   char cc = 'a' ; 
   while(cc<='z')
   {
      best = max(best,f[cc++]) ; 
   }
   int need = n-best ; 
   if(k>=need)
   {
      cout << "1" << endl ; return 0 ; 
   }
   int ans = n ; 
   if(n%2==1)
   {
      cout << n << endl ; return 0 ; 
   }
   map < char ,int > a,b ; 
   int idx = 1 ,h = n/2 ; 
   for(auto c : s )
   {
      if(idx<=h)
      {
         a[c]++ ; 
      }
      else
      {
         b[c]++ ; 
      }
      idx++ ; 
   }
   cc = 'a' ; 
   int x = 0 , y = 0 ; 
   while(cc<='z')
   {
      x+=max(0,a[cc]-b[cc]) ; 
      cc++ ; 
   }
   cc = 'a' ; 
   while(cc<='z')
   {
      y+=max(0,b[cc]-a[cc]) ; 
      cc++ ; 
   }
   need = min(x,y) ; 
   ans = n ; 
   if(need<=k)
   {
      ans = n/2 ; 
   }
   cout << ans << endl ;
   return 0 ;
}