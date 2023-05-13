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
const ll maxx = 20 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
string s[maxx] ; 
int main()
{
   debugMode();
   int n ;
   cin >> n ; 
   s[1] = "1" ; 
   if(n==1)
   {
      cout << s[1] << endl ; 
      return 0 ; 
   }
   for(int i=2;i<=n;i++)
   {
      string k="" ; 
      char c,d ; 
      int x = i%10 ; 
      c = x+'0' ; 
      x = i/10 ; 
      k+=c ; 
      if(x>0)
      {
         d = x+'0' ; 
         k+=d;
      } 
      reverse(k.begin(),k.end()) ;
      if(i==n)
      {
         int idx = 0 ; 
         for(auto c : s[i-1])
         {
            if(idx!=0){cout << " " ; }
            cout << c ; 
            idx = 1 ; 
         }
         cout << " " <<  k ;
         for(auto c : s[i-1])
         {
            if(idx!=0){cout << " " ; }
            cout << c ; 
         }
         cout << endl  ;
         return 0 ; 
      }

      string temp = s[i-1]+k+s[i-1] ; 
      s[i] = temp ; 
   }
   
   return 0 ;
}