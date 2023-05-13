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
ll n,ar[maxx+10] ; 
bool valid(ll r,ll h)
{
   ll g = 2 ; 
   ll b = qq ; 
   ll l = qq ; 
   while(l<=r)
   {
      ll x = ar[l] ; 
      if(x>=h)
      {
         if(g>zz && (h*tt)>=x )
         {
            g-- ; 
            h = h*tt ; 
         }
         else if(b>zz && (h*3LL)>=x)
         {
            h = h*3LL ; 
            b-- ; 
         }
         else if(g>qq && (h*tt*tt)>=x)
         {
            h = h*4LL ; 
            g-=tt ; 
         }
         else{return false ; }
      }
      cout << h << endl ;
      ll add = x/tt ; 
      h+=add ; 
      l++ ; 
   }
   return true ; 
}
void solve()
{
   ll h ; 
   cin >> n >> h  ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   sort(ar+1,ar+n+1) ; 
   ll l = qq , r = n , ans = zz   ;
   while(l<=r)
   {
      ll m = (l+r)/tt ; 
      if(valid(m,h))
      {
         ans = m ; 
         l = m+qq ; 
      }
      else
      {
         r = m-qq ; 
      }
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