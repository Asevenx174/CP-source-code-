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

freopen("output2.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n ; 
ll get(ll x)
{
   ll ans = x*(x+qq) ; 
   ans = ans/tt ; 
   return ans ; 
}
void solve()
{
   cin >> n ; 
   ll need = get(tt*n) ; 
   ll f = get(n) ; 
   ll d = need-f ; 
   if(d%n!=zz)
   {
      cout << "No" << endl ; return ;
   }
   cout << "Yes" << endl ;
   ll idx = (d/n)+qq ;
   ll temp = n ; 
   ll i = 1 ; 
   while(temp--)
   {
      ll a = i ; 
      ll b = idx-a ; 
      cout << a << " " << b << endl ;
      idx++ ; 
      i+=tt ; 
      if(i>n){i=tt;}
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