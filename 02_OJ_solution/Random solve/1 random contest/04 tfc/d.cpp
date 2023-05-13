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
const ll maxx = 2e5+10,mod=23,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,br[maxx+5][mod+5],co[mod+10] ; 
void solve()
{
   std::vector < ll > last[mod+4];
   cin >> n ;
   for (int i = 0; i <=mod ; ++i)
   {
      last[i].push_back(zz) ; 
      co[i] = 0 ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   ll ans = 0 ; 
   for(int i=1;i<=n;i++)
   {
      ll x = ar[i] ; 
      ll idx = 0 ; 
      ll r = i ; 
      ll l = 0 ; 
      while(idx<mod)
      {
         ll temp = qq << idx ; 
         if(temp&x)
         {
            auto it = last[idx].rbegin() ; 
            ll pos = *it ; 
            l = max(l,pos) ; 
            last[idx].push_back(i) ;   
            co[idx]++ ; 
         }
         else if(co[idx]>qq)
         {
            auto it = last[idx].rbegin() ; 
            it++ ; 
            ll pos = *it ; 
            l = max(l,pos) ; 
         }
         idx++ ; 
      }
      ll add = r-l ; 
      //add = add*(add+qq) ; 
      //add = add / tt ; 
      ans+=add ; 
   }
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