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
/// vector<vector<int>> vec( n , vector<int> (m));
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=1e10+5,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,ar[maxx+10],f[maxx+10],ans[maxx+10] ;
ll best[maxx+10] ;  
void solve()
{
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   ans[1] = 1 ; 
   for(int i=2;i<=n;i++)
   {
      ll s = ans[i-1] ;
      ll l = i-s ; 
      ll r = i-1 ;  
      ll a = ar[i]-(s+1) ; 
      ll b = ar[i]-ar[i-s] ; 
      if(i<=ar[i])
      {
         ans[i] = ans[i-1]+1 ; 
         best[i] = best[i-1]*ar[i] ; 
      }
      else
      {
         ans[i] = ans[i-1] ; 
         ll temp = best[i-1]/ar[i-s] ; 
         temp = temp*ar[i] ; 
         best[i] = temp ;  
      }
   }
   for (int i = 0; i < n ; ++i)
   {
      if(i>0){cout << " " ; }
      cout << ans[i+1] ; 
   }
   cout << endl ; 
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