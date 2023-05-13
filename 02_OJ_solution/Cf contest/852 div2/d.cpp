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
ll n,ar[maxx+10][5],br[maxx+10][5],lr[maxx+10][5],rr[maxx+10][5] ; 
ll ex(ll x)
{
   ll add = x*(x+qq) ; 
   add = add/tt ; 
   return add ; 
}
void solve()
{
   cin >> n ; 
   for (int i = 0; i < n ; ++i)
   {
      ll x ;
      cin >> x ;
      ar[i+1][1] = x ; 
      br[x][1] = i+1 ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      ll x ;
      cin >> x ;
      ar[i+1][2] = x ;
      br[x][2] = i+1 ;
   }
   ll a = mod ; 
   ll b = 0 ; 
   for(int i=1;i<=n;i++)
   {
      ll x = br[i][1] ; 
      a = min(a,x) ; 
      b = max(b,x) ; 
      lr[i][1] = a ; 
      rr[i][1] = b ; 
   }
   a = mod ; 
   b = 0 ; 
   for(int i=1;i<=n;i++)
   {
      ll x = br[i][2] ; 
      a = min(a,x) ; 
      b = max(b,x) ; 
      lr[i][2] = a ; 
      rr[i][2] = b ; 
   }
   ll ans = qq ; 
   for(int i=2;i<=n;i++)
   {
      ll l = min(lr[i-1][1],lr[i-1][2]) ;
      ll r = max(rr[i-1][1],rr[i-1][2]) ; 
      a = min(br[i][1],br[i][2]) ; 
      b = max(br[i][1],br[i][2]) ;
      if(a<l && r<b)
      {
         ll add = (l-a)*(b-r) ; 
         ans+=add ; 
         //cout << add << endl ; 
      }
      else if(b<l)
      {
         ll add = (l-b)*(n-r+qq) ; 
         ans+=add ;
      }
      else if(r<a)
      {
         ll add = (a-r)*l ; 
         ans+=add ;  
      }
      //cout << i << " ->> " << endl ;
      //cout << l << " " << r << endl ;
     // cout << a << " " << b << endl ;
   }
   a = min(br[1][1],br[1][2]) ; 
   b = max(br[1][1],br[1][2]) ;
   ans+=ex(b-a-qq);
   ans+=ex(n-b);
   ans+=ex(a-qq);  
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