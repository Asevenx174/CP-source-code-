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
ll lcm(ll a,ll b)
{
   ll ans = (a*b)/__gcd(a,b) ; 
   return ans ; 
}
bool calco(ll x)
{
   std::vector < bool > used(15,false) ;
   //return false ; 
   ll ans = 1 ; 
   ll temp = x ; 
   while(temp>9LL)
   {
      ll y = temp%10LL ; 
      if(!used[y] && y>zz){used[y]=true;ans = lcm(ans,y) ;} 
      temp = temp/10LL ; 
   }
   ans = lcm(ans,temp) ;
   if(x%ans==zz){return true;}
   return false ;  
}
void solve()
{
   ll n ;
   cin >> n ; 
   ll x = n ; 
   n+=3000LL ; 
   while(x<=n)
   {
      //cout << x << " " << n << endl ;
      if(calco(x))
      {
         cout << x << endl ; return ; 
      }
      x++ ; 
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