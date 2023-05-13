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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10] ; 
void solve()
{
   int n,s ;
   cin >> n >> s ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   sort(ar+1,ar+n+1) ; 
   int idx = (n+1)/2 ; 
   ll ans = abs(s-ar[idx]) ; 
   if(s>ar[idx+1])
   {
      for (int i = idx+1 ; i <= n ; ++i)
      {
         ans+=max(s-ar[i],0) ; 
      }
   }
   if(ar[idx-1]>s)
   {
      for (int i = idx-1 ; i>0 ; --i)
      {
         ans+=max(ar[i]-s,0) ; 
      }
   }
   cout << ans << endl ; 
}
int main()
{
   debugMode();
   ll test = 1 ; 
   //cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}