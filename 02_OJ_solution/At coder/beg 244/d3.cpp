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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll a[maxx],n,b[maxx],val[maxx]; 
int main()
{
   debugMode();
   cin >> n ; 
   for(int i=1;i<=n;i++){cin >> a[i] ;}
   ll idx = 1,d=0; 
   while(idx<=n)
   {
      ll temp = 1 ; 
      while(idx+1<=n && a[idx]==a[idx+1])
      {
         temp++ ; 
         idx++ ; 
      }
      b[++d]=temp;
      val[d]=a[idx] ;
      idx++; 
   }
   ll sum = 0 ; 
   for(int i=1;i<=d;i++)
   {
      ll f = b[i] ; 
      ll v = val[i] ; 
      if(f==v)
      {
         for(int add=1;add<=f;add++)
         {
            sum++ ;
            if(add==f){sum-=f;}
            cout << sum << endl ;
         }
      }
      else
      {
         for(int add=1;add<=f;add++)
         {
            sum++ ;
            cout << sum << endl ;
         }
      }
   }
   return 0 ;
}