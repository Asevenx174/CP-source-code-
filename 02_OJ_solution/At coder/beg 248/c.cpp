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
const ll maxx = 18 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
string getstr(int x)
{
   string s = "" ; 
   while(x>9)
   {
      int y = x%10 ; 
      char c = y+'0' ; 
      s+=c ;  
      x = x/10 ; 
   }
   char c = x+'0' ; 
   s+=c ; 
   reverse(s.begin(),s.end()) ; 
   return s ; 
}
string s[maxx+5] ; 
int main()
{
   debugMode();
   s[1] = "1" ; 
   for(int i=2;i<=16;i++)
   {
      s[i] = s[i-1]+getstr(i)+s[i-1] ; 
   }
   int n ;
   cin >> n ;
   if(n==1)
   {
      cout << s[n] << endl ; return 0 ; 
   }
   int idx = 0 ; 
   for(auto c : s[n-1] )
   {
      if(idx!=0){cout << " " ;}
      idx = 1 ; 
      cout << c ; 
   }
   cout << n ; 
   for(auto c : s[n-1] )
   {
      idx = 1 ; 
      cout << " " <<  c ; 
   }
   cout << endl ;
   return 0 ;
}