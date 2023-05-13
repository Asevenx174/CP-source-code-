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
ll n,x ; 
bool valid(ll m)
{
  ll l = n ; 
  ll r = m ; 
  ll len = r-l+qq ; 
  for (ll i = 0; i < 65 ; ++i)
  {
     ll y = qq << i ; 
     if( (x&y)!=zz )
     {
        // 1 
        //cout << y << endl ; 
        if( (l&y)==zz || (r&y)==zz ){ return false ; }
        if(i>len){return false; }
     }
     else
     {
        // 0 
        //cout << y << endl ; 
        if( (l&y)!=zz && (r&y)!=zz && (i<=len) ){ return false ; }
     }
  }
  return true ; 
}
void solve()
{
   cin >> n >> x ; 
   if( (n&x)!=x )
   {
      cout << "-1" << endl ; return ; 
   }
   if(n==x)
   {
      cout << n << endl ; return ; 
   }
   for( ll i = 0; i < 65 ; ++i)
   {
      ll y = qq << i ; 
      if( valid(n+y) )
      {
         cout << n+y << endl ; return  ; 
      }
   }
   cout << "-1" << endl ; 
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