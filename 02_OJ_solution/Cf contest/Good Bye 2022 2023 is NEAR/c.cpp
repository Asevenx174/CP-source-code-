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
const ll maxx = 100+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,br[maxx+10] ; 
bool calco(ll add)
{
   ll a = 0 ; 
   ll b = 0 ; 
   for (int i = 0; i < n ; ++i)
   {
      br[i+1] = ar[i+1]+add ; 
   }
   for(int i=1;i<n;i++)
   {
      for(int j=i+1;j<=n;j++)
      {
         if(__gcd(br[i],br[j])>qq){return false;}
      }
   }
   return true ; 
}
void solve()
{
   ll p=0,q=0 ; 
   set < ll > a,b ; 
   cin >> n ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ;
      a.insert(ar[i+1]) ; 
      b.insert( ar[i+1]%3LL ) ;
      if(ar[i+1]%tt){p++;}else{q++;}
   }
   ll f ; 
   if(b.size()==3)
   {
      f = 0 ; 
      for(int i=1;i<100;i++)
      {
         if(calco(i)){f=1;}
      }
       if(f)
   {
      cout << "YES" << endl ;
   }
   else 
   {
      cout << "NO" << endl ;
   }
   return ;
   }
   f = 1 ; 
   if(a.size()!=n || min(p,q)>qq ){f=0;}
   if(f)
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