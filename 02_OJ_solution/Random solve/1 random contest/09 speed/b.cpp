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
const ll maxx = 300+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10][maxx+10] ; 
int br[maxx+10][maxx+10] ; 
int n,m ; 
int calco(int i,int j)
{
   int val = 0 ; 
   if( (i==1 && j==1) || (i==1 && j==m) || (i==n && j==1) || (i==n && j==m) )
   {
      val = 2 ; 
   }
   else if( i==1 || j==1 || i==n || j==m)
   {
      val = 3 ; 
   }
   else
   {
      val = 4 ; 
   }
   return val ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int f = 1 ; 
      cin >> n >> m ;
      for (int i = 1 ; i <= n ; ++i)
      {
         for (int j = 1 ; j <=  m ; ++j )
         {
            int x ;
            cin >> x ;
            ar[i][j] = x ; 
            br[i][j] = calco(i,j) ; 
            if(ar[i][j]>br[i][j]){f=0;}
         }
      }
      if(f==0)
      {
         cout << "NO" << endl ;
      }
      else
      {
         cout << "YES" << endl ;
         for (int i = 1 ; i <= n ; ++i)
      {
         for (int j = 1 ; j <=  m ; ++j )
         {
            if(j>1){cout << " " ;}
            cout << br[i][j] ; 
         }
         cout << endl ;
      }
      }
   }
   return 0 ;
}