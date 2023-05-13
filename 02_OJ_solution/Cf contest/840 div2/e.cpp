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
void solve()
{
   //std::vector < int > v {33554431,2,3,4,6,7,8,14,15,16,30,31,32,62,63,64,127,128,129};
   std::vector < int > v ;
   int q ; 
   cin >> q ;
   int add = 2 ; 
   while(q--)
   {
      int x = add-1 ;
      v.push_back(x) ; 
      add = add*2 ; 
   }
   for(auto a : v)
   {
      int ans = 0 ; 
      for(int b=1;b<a;b++)
      {
         ans = max(ans,__gcd(a^b,a&b)) ; 
      }
      cout << ans << endl ;
   }
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