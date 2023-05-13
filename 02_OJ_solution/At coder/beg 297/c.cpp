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
const ll maxx = 3e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n,br[maxx+10] ; 
bool check()
{
   for (int i = 0; i < n ; ++i)
   {
      if(ar[i+1]!=br[i+1]){return false;}
   }
   return true ; 
}
bool valid()
{
   for (int i = 0; i < n ; ++i)
   {
      br[i+1] = ar[i+1] ; 
   }
   sort(br+1,br+n+1) ; 
   if(check()){return true;}
   sort(br+1,br+n+1,greater<int>()) ; 
   if(check()){return true;}
   return false ; 
}
void solve()
{
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   if(n==2 && ar[1]>ar[2])
   {
      cout << "NO" << endl ; return ;
   }
   for(int i=2;i<=n;i++)
   {
      br[i-1] = ar[i]-ar[i-1] ; 
   } 
   int ans = 1 ; 
   br[2] = 2*mod ; 
   br[n-2] = 2*mod ; 
   for(int i=1;i<n;i++)
   {
      if(br[i]>=0){continue;}
      int need = -br[i] ; 
      if(i-2>0 && br[i-2]>0)
      {
         int sub = min(need,br[i-2]) ; 
         br[i]+=sub ; 
         need-=sub ; 
      } 
      if(i+2<n && br[i+2]>0)
      {
         int sub = min(need,br[i+2]) ; 
         br[i]+=sub ; 
         need-=sub ; 
         br[i+2]-sub ; 
      } 
      if(need>0){ans=0;}
   }
   if(ans)
   {
      cout << "YES" << endl ;
   }
   else
   {
      cout << "NO" << endl ;
   }
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
