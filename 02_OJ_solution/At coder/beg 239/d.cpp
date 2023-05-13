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
const ll maxx = 200+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int a,b,c,d ;
bool prime[maxx+10] ; 
void calco()
{
   for(int i=2;i<maxx;i++)
   {
      int f = 0 ; 
      for(int j=2;j<i;j++)
      {
         if(i%j==0){f=1;}
      }
      if(f==0){prime[i]=true;}
   }
}
bool valid(int x)
{
   for(int i=c;i<=d;i++)
   {
      if(prime[i+x]){return false;}
   }
   return true ; 
}
int main()
{
   debugMode();
   calco();
   cin >> a >> b >> c >> d ; 
   int f = 0 ; 
   for(int i=a;i<=b;i++){if(valid(i)){f=1;}}
   if(f)
   {
      cout << "Takahashi" << endl ;
   }
   else
   {
      cout << "Aoki" << endl ;
   }
   return 0 ;
}