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

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=60,imax=2e9+10,qq=1,zz=0;

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
      ll n ;
      cin >> n ; 
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i] ; 
      }
      ll ans = 0,sum=0 ; 
      std::vector < ll > v ;
      for (int i = 0; i < n ; ++i)
      {
         ll x = ar[i] ; 
         while(x%2LL==zz)
         {
            x = x/2LL ; 
            ans++ ; 
         }
         x = i+1 ; 
         ll temp = 0 ; 
         while(x%2LL==zz)
         {
            x = x/2LL ; 
            temp++ ; 
         }
         if(temp>0)
         {
            v.push_back(temp) ; 
            sum+=temp ; 
         }
      }
      if(ans>=n)
      {
         cout << "0" << endl ; continue ; 
      }
      ll need = n-ans ; 
      if(need>sum)
      {
         cout << "-1" << endl ; continue ; 
      }
      ll op = 0 ; 
      sort(v.begin(),v.end(),greater<ll>()) ; 
      auto it = v.begin() ; 
      while(need>0)
      {
         ll x = *it ; it++ ; 
         need-=x ; 
         op++ ; 
      }
      cout << op << endl ;
   }
   return 0 ;
}