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
int ar[25],n ; 
void solve()
{
   cin >> n ; 
   string sr ;
   cin >> sr ;
   int idx = 1 ; 
   for(auto c : sr)
   {
      int x = c=='1' ? 1 : 0 ; 
      ar[idx++] = x ; 
   }
   ll s = 0 ; 
   ll b = 0 ; 
   for(ll i=1;i<=n;i++)
   {
      ll x = ar[i] ; 
      if(x==qq)
      {
         s+=(s+qq) ; 
      }
      else
      {
         b+=(b+qq) ; 
      }
   }
   ll r = qq << n ; 
   ll l = s+qq ; 
   r-=b ; 
   idx = 0 ; 
   while(l<=r)
   {
      if(idx!=zz){cout << " " ;}
      cout << l ; 
      idx = 1 ; 
      l++ ; 
   } 
   cout << endl ;
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