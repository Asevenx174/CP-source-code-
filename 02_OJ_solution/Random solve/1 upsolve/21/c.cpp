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
const ll maxx = 100+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],br[maxx+10],n ; 
int ev(int x)
{
   int f = x%2==0 ? 1 : 0 ; 
   return f ; 
}
int ans = 0 ; 
void calco(int idx,int p)
{
   if(idx>n)
   {
      if(p){ans++;}
      return ; 
   }
   calco(idx+1,ev(ar[idx])|p) ;
   calco(idx+1,ev(ar[idx]+1)|p) ;
   calco(idx+1,ev(ar[idx]-1)|p) ;
}
void solve()
{
   ans = 0 ; 
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   calco(2,ev(ar[1])) ;
   calco(2,ev(ar[1]+1)) ;
   calco(2,ev(ar[1]-1)) ; 
   cout << ans << endl ;
}
int main()
{
   debugMode();
   ll test = 1 ; 
   // cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}