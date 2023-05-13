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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n ; 
bool calco(int x)
{
   int p = 0 ; 
   for (int i = 0; i < n ; ++i)
   {
      int y = abs(ar[i+1]-x) ; 
      if(p>y){return false;}
      p = y ; 
   }
   return true ; 
}
void solve()
{
   cin >> n ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   int l = 1e9 ; 
   int r = 0 ; 
   for(int i=2;i<=n;i++)
   {
      int a = ar[i-1] ; 
      int b = ar[i] ; 
      if(a<b)
      {
         int x = (a+b)/2 ; 
         l = min(l,x) ; 
      }
      else if(a>b)
      {
         int x = (a+b+1)/2 ; 
         r = max(r,x) ; 
      }
      //cout << l << " " << r << endl ;
   }
   if(r <= l) cout << r << endl;
   else cout << -1 << endl ;
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