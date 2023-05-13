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

#define SL(a)              scanf("%I64d",&a)
#define SLL(a,b)           scanf("%I64d %I64d",&a,&b)
#define PL(x) printf("%I64d\n",(x))
#define PLL(x,y) printf("%I64d %I64d\n",x,y)

#define S(a)              scanf("%d",&a)
#define SS(a,b)           scanf("%d %d",&a,&b)
#define P(x) printf("%d\n",(x))
#define PP(x,y) printf("%d %d\n",x,y)

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 5e4+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      std::vector < pii > p,q ;
      ll n,m ;
      cin >> n >> m ; 
      for (int i = 0; i < n ; ++i)
      {
         ll x ;
         cin >> x ;
         ll t = 1 ; 
         while(x%m==0)
         {
            x = x / m ; 
            t = t*m ; 
         }
         p.push_back({x,t}) ; 
      }
      ll k ;
      cin >> k ; 
      for (int i = 0; i < k ; ++i)
      {
         ll x ;
         cin >> x ;
         ll t = 1 ; 
         while(x%m==0)
         {
            x = x / m ; 
            t = t*m ; 
         }
         q.push_back({x,t}) ; 
      }
      auto it = p.begin() ; 
      auto lt = q.begin() ; 
      pii a = *it ; 
      pii b = *lt ; 
      while(it!=p.end() && lt!=q.end())
      {
         if(a.ff!=b.ff){break;}
         if(a.ss>b.ss)
         {
            a = {a.ff,a.ss-b.ss} ; 
            lt++ ; 
            if(lt==q.end()){break;}
            b = *lt ;  
         }  
         else if(b.ss>a.ss)
         {
            b = {b.ff,b.ss-a.ss} ; 
            it++ ; 
            if(it==p.end()){break;}
            a = *it ;  
         } 
         else
         {
            it++ ; 
            lt++ ; 
            if(it==p.end() || lt==q.end()){break;}
            a = *it ; 
            b = *lt ; 
         }
      }
      if(it==p.end() && lt==q.end())
      {
         cout << "YES" << endl ;
      }
      else
      {
         cout << "NO" << endl ;
      }
   }
   return 0 ;
}