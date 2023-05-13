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
const ll maxx = 15 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      n = 10 ; 
      string s ;
      cin >> s ;
      int idx = 1 ;
      for(auto c : s )
      {
         int x = 2  ;
         if(c=='1'){x=1;}else if(c=='0'){x=0;}
         ar[idx++] = x ;  
      }
      int a = 0 ; 
      int b = 0 ;
      int p = 5 ; 
      int q = 5 ; 
      int c = 0 ; 
      int d = 0 ; 
      int ans ;
      for(int i=1;i<=n;i++)
      {
         ans = i ; 
         if(ar[i]==0)
         {
            if(i%2==1){a++;}else{b++;}
         }
         if(ar[i]==2)
         {
            if(i%2==1){c++;}else{d++;}
         }
         if(i%2==1){p--;}else{q--;}
         // odd win
         int x = (5-p)-a ; 
         int y = (5-q)-b-d+(q) ; 
         if(y<x){break;}
         x = (5-p)-a-c+p ; 
         y = (5-q)-b ;
         if(y>x){break;}
      }
      cout << ans << endl ; 
   }
   return 0 ;
}