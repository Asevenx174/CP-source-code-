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

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int calco(int y,int g)
{
   int k = y/g ; 
   k++ ; 
   k = k*g ; 
   int ans = k-y ;
   return ans ; 
}
int lowdiv(int x,int yy)
{
   int best = mod ; 
   int y = sqrt(x) ; 
   for(int i=2;i<=y;i++)
   {
      if(x%i==0)
      {
         int j = x/i ; 
         best = min(best,calco(yy,i)) ;
         best = min(best,calco(yy,j)) ;  
      }
   }
   return best ;  
}
void solve()
{
   std::vector < pii > v ;
   int n ;
   cin >> n ; 
   for (int i = 0; i < n ; ++i)
   {
      int x,y ; 
      scanf("%d %d",&x,&y) ; 
      v.push_back({x,y}) ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      int x = v[i].ff ; 
      int y = v[i].ss ; 
      int d = y-x ; 
      int g = __gcd(x,y) ; 
      int ans = -1 ; 
      if(g!=1)
      {
         ans = 0 ; 
      }
      else
      {
         ans = lowdiv(y-x,y) ; 
         if(ans==mod)
         {
            ans = -1 ; 
         }
      }
      printf("%d\n",ans) ; 
   }
}
int main()
{
   debugMode();
   //cout << __gcd(10009+79,20000+79) << endl ;
   ll test = 1 ; 
   //cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}