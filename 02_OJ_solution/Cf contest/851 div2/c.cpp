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
ll n,sum ; 
ll get(ll m)
{
   ll ans = m*(m+qq) ; 
   ans = ans/tt ; 
   return ans ; 
}
ll valid(ll m)
{
   ll a = get(m-1) ; 
   ll b = get(m+n-qq) ;
   ll ans = b-a ; 
   return ans ; 
}
void solve()
{
   cin >> n ;
   sum = get(tt*n) ; 
   //cout << n << " " << sum << endl ; 
   ll l=qq,r=2*n,ans=0 ;
   while(l<=r)
   {
      cout << l << " " << r << endl ;
      ll m = (l+r)/tt ; 
      ll temp = valid(m) ; 
      if(temp==sum)
      {
         ans = m ;  
      }
      else if(temp>sum)
      {
         r = m-qq ; 
      }
      else
      {
         l = m+qq ; 
      }
   }
   if(ans==zz){cout << "NO" << endl ;return ;}
   cout << "YES" << endl ; 
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