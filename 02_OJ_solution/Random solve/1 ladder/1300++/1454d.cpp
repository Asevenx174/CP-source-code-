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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll oc[maxx+10],best,idx; 
void gen(ll x)
{
   for(ll i=2;i*i<=x;i++)
   {
      if(x%i==0)
      {
         ll temp = 0 ; 
         while(x%i==0)
         {
            temp++ ; 
            x = x/i ; 
         }
         oc[i] = temp ; 
         if(best<temp)
         {
            best = temp ; 
            idx = i ; 
         } 
      }
   }
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      best = 0 ; 
      idx = 0 ; 
      ms(oc,0) ; 
      ll x ;
      cin >> x ;
      gen(x) ; 
      if(best<2)
      {
         cout << "1" << endl ; 
         cout << x << endl ; 
         continue ; 
      }
      cout << best << endl ;
      for(int i=1;i<best;i++)
      {
         if(i!=1){cout << " " ; }
         cout << idx ; 
      }
      ll mul = 1 ; 
      ll temp = best ;
      while(temp--)
      {
         mul = mul*idx ; 
      }
      ll d = x/mul ; 
      idx = idx*d ; 
      cout << " " <<  idx << endl ;
   }
   return 0 ;
}