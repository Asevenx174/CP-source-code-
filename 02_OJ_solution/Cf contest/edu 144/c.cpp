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
const ll maxx = 1e5+10,mod=998244353,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll l,r,s,t,val,a,b,temp ;
ll get1(ll x)
{
   x = x*val ; 
   if(x<=r){return true;}
   return false ; 
} 
ll calco1()
{
   a = l-qq ; 
   ll p=l,q=r ; 
   while(p<=q)
   {
      ll x = (p+q)/tt ; 
      if(get1(x))
      {
         a = x ; 
         p = x+qq ;  
      }
      else
      {
         q = x-qq ; 
      }
   }
}
ll get2(ll x)
{
   x = x*temp ; 
   if(x<=r){return true;}
   return false ; 
} 
ll calco2()
{
   ll p=l,q=r ; 
   while(p<=q)
   {
      ll x = (p+q)/tt ; 
      if(get2(x))
      {
         b = x ; 
         p = x+qq ;  
      }
      else
      {
         q = x-qq ; 
      }
   }
}
void solve()
{
   cin >> l >> r ; 
   s = 1 ; 
   ll x = l ; 
   while(x*tt<=r)
   {
      x = x*tt ; s++ ; 
   }
   val = qq ; 
   temp = qq ; 
   ll co = s-qq ; 
   while(co--)
   {
      temp = temp*tt ; 
   }
   val = 3LL ; 
   co = max(zz,s-tt) ; 
   while(co--)
   {
      val = val*tt ; 
   } 
   calco1() ; 
   calco2() ; 
   //cout << a << " " << b << endl ;
   ll ans = (a-l+qq)*s+(b-a) ; 
   ans = ans%mod ; 
   cout  << s << " " << ans << endl ;
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