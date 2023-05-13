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
ll n,x,y ; 
ll gen(ll p,ll r)
{
   
}
ll calco(int i,int j,int k)
{
   int z = n ; 
   if(x<i || y<j){ return 1 ;}
   ll ans = 1 ; 
   ans = (ans*gen(x-1,i-1)) ;
   ans = (ans*gen(y-x-1,j-i-1)) ;
   ans = (ans*gen(z-y-1,k-j-1)) ;
   return ans ; 
}
void solve()
{
   int i,j ;
   cin >> n >> i >> j >> x >> y ; 
   if(x>y)
   {
      int a = n-i+1 ; 
      int b = n-j+1 ; 
      i = b ; 
      j = a ; 
      swap(x,y) ; 
   }
   if(x<i || y<j){ cout << "0" << endl ; return ;}
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
}