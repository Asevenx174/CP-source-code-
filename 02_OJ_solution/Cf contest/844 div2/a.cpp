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
int a,b,f,g,w,d,h ;
int calco(int x,int y)
{
  int ans = h+abs(x-f)+abs(y-g)+abs(x-a)+abs(y-b) ;
  return ans ; 
}
void solve()
{
   cin >> w >> d >> h ;  
   cin >> a >> b >> f >> g ; 
   int ar[10] ; 
   ar[1] = calco(0,g) ;
   ar[2] = calco(f,0) ;
   ar[3] = calco(w,g) ;
   ar[4] = calco(f,d) ;      
   int ans = mod ; 
   for (int i = 0; i < 4 ; ++i)
   {
      ans = min(ans,ar[i+1]) ; 
   }
   cout << ans << endl ; 
}
int main()
{
   debugMode();
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}