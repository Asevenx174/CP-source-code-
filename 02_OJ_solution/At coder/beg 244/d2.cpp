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
const ll maxx = 1e5+10,mod=1e9+7,imax=1e18,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int main()
{
   debugMode();
   ll n,x ;
   cin >> n >> x ;
   string s,k  ;
   cin >> k ; 
   stack < char > stk,str; 
   for(auto c : k )
   {
      stk.push(c) ; 
   }

   while(!stk.empty())
   {
      char c = stk.top() ; 
      stk.pop() ; 
      if(!str.empty())
      {
          char p = str.top() ; 
          if( ( p=='U' && c=='L' ) || ( p=='U' && c=='R' ) )
          {
             str.pop() ; 
          }
          else
          {
             str.push(c) ; 
          }
      }
      else
      {
         str.push(c) ; 
      }
   }

   while(!str.empty())
   {
      char c = str.top() ; 
      str.pop() ; 
      ll temp = x ; 
      if(c=='U')
      {
        x = x/2LL ; 
      }
      else if(c=='L')
      {
        x = 2LL*x ; 
      }
      else
      {
        x = 2LL*x ;
        x++ ; 
      }
      if(x>imax){x=temp;}
   }
   cout << x << endl ;
   return 0 ;
}