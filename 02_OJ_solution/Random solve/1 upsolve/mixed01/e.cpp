#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll a,b,n ; 
bool f1(ll i,ll j)
{
   ll p = i-a ; 
   ll q = j-b ; 
   ll l = min(p,q) ; 
   ll r = max(p,q) ; 
   if(l!=r){return false ; }
   if(max(1-a,1-b)<=l && r<=min(n-a,n-b))
   {
       return true ; 
   }
   return false ; 
}

bool f2(ll i,ll j)
{
   ll p = i-a ; 
   ll q = b-j ; 
   ll l = min(p,q) ; 
   ll r = max(p,q) ; 
   if(l!=r){return false ; }
   if(max(1-a,b-n)<=l && r<=min(n-a,b-1))
   {
       return true ; 
   }
   return false ; 
}
int main()
{
   debugMode();
   cin >> n >> a >> b ; 
   ll p,q,r,s ;
   cin >> p >> q >> r >> s ;
   for(ll i=p;i<=q;i++)
   {
      for(ll j=r;j<=s;j++)
      {
         char c = '.' ; 
         if(f1(i,j) || f2(i,j) )
         {
            c = '#' ; 
         }
         printf("%c",c) ; 
      }
      printf("\n") ; 
   }
   return 0 ;
}