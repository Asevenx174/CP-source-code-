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
ll ar[maxx+10],br[maxx+10],n,m ; 
int get()
{
   int ans = mod ; 
   int idx = 0 ; 
   for (int i = 0; i < n ; ++i)
   {
      if(ar[i+1]<ans)
      {
         ans = ar[i+1] ; 
         idx = i+1 ; 
      }
   }
   return idx ; 
}
void solve()
{
   cin >> n >> m ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   for (int i = 0; i < m ; ++i)
   {
      cin >> br[i+1] ; 
   }
   for (int i = 0; i < m ; ++i)
   {
      ll x = br[i+1] ; 
      ll idx = get() ; 
      swap(ar[idx],x) ; 
   }
   ll sum = 0 ; 
   for (int i = 0; i < n ; ++i)
   {
      sum+=ar[i+1] ; 
   }
   cout << sum << endl ;
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