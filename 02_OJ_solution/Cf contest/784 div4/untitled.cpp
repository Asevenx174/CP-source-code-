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
int dp[maxx][5] ; 
void calco(int x)
{
   deque < int > dq ; 
   int temp = x ; 
   while(temp!=0)
   {
      dq.push_front(temp) ; 
      temp = dp[temp][1] ;  
   }
   temp = dp[x][2] ; 
   while(temp!=0)
   {
      dq.push_back(temp) ; 
      temp = dp[temp][2] ;
   }
   temp = 0 ; 
   cout << dq.size() ; 
   while(!dq.empty())
   {
      temp = dq.front() ; 
      dq.pop_front() ; 
      cout << " " <<  temp ; 
   }
   cout << endl ; 
   return ; 
}
int main()
{
   debugMode();
   int n,q ;
   cin >> n >> q ;
   while(q--)
   {
      int s,x,y ;
      cin >> s ; 
      if(s==1)
      {
         cin >> x >> y ; 
         dp[x][2]=y ; 
         dp[y][1]=x ; 
      }
      else if(s==2)
      {
         cin >> x >> y ; 
         dp[x][2]=0 ; 
         dp[y][1]=0 ; 
      }
      else
      {
         cin >> x ; 
         calco(x) ; 
      }
   }
   return 0 ;
}