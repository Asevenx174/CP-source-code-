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
ll n,x,l[maxx],sum=0;
std::vector < ll > a[maxx] ;
void calco(ll idx, ll mul)
{
   if(idx>n)
   {
      if(mul==x){sum++;}
      return ; 
   }
   for(auto y : a[idx])
   {
      ll temp = mul*y ;
      if(temp<=x)
      {
         calco(idx+1,temp) ;
      }
   }
   return ; 
}
int main()
{
   debugMode();
   cin >> n >> x ; 
   ll mul = 1 ; 
   for (int i = 0; i < n ; ++i)
   {
      int j = i+1 ; 
      cin >> l[j] ; 
      for(int k=1;k<=l[j];k++)
      {
         ll y ; 
         cin >> y ; 
         a[j].push_back(y) ; 
         mul = mul*y ; 
      }
   }
   if(x>mul){cout << "0" << endl ; return 0 ; }
   calco(1,1) ; 
   cout << sum << endl ;
   return 0 ;
}