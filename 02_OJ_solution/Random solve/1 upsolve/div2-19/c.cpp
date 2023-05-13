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
const ll maxx = 61 ,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
void solve()
{
   ll n,k,f=0,l=0,r=mod,ze=0,co=0 ;
   cin >> n >> k ; 
   for( ll i=maxx;i>=zz;i--)
   {
      ll temp = qq << i ; 
      if( (n&temp) )
      {
         if(f==zz){l=i;}
         f = qq ; 
      }
      else if(f)
      {
         if(ze==zz){r=i;}
         ze = qq ; 
      }
      if(f){co++;}
   }
   if(k>co)
   {
      ll ans = 0 ; 
      for ( ll i = 0; i < k ; ++i)
      {
         ll temp = (qq<<i) ;   
         ans+=temp ;
      }
      cout << ans << endl ; 
      return ;
   }
   ll len = l-r ; 
   //cout << l <<  " " << r << endl ;
   if(r!=mod && len<k)
   {
      len++ ; 
      ll ans = 0 ; 
      ll temp = len ; 
      ll add = qq << l ;  
      while(temp>zz)
      {
         ans+=add ; 
         add = add/tt ;
         temp-- ;  
      } 
      add = qq ; 
      k-=len ; 
      while(k>zz)
      {
         ans+=add ; 
         add = add*tt ; 
         k-- ; 
      }
      cout << ans << endl ; 
      return ; 
   }
    
   ll ans = qq << (l+qq) ; 
   k-- ; 
   ll add = qq ; 
   while(k>zz)
   {
      ans+=add ; 
      k-- ; 
      add = add*tt ; 
   }
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