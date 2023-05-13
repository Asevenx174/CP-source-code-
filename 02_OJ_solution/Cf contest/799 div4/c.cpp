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
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 10 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int fx[10] = {-1,-1,1,1} ; 
int fy[10] = {-1,1,1,-1} ; 
int ar[maxx+10][maxx+10],br[maxx][maxx] ; 
bool valid (int a,int b)
{
   ms(br,0) ; 
   for(int m=0;m<10;m++)
   {
      for(int i=0;i<4;i++)
      {
         int x = a+fx[i]*m ; 
         int y = b+fy[i]*m ; 
         if(min(x,y)>0 && max(x,y)<=8)
         {
            br[x][y] = 1 ; 
         } 
      }
   }
   int ans = 1 ; 
   for (int i = 0; i < 8 ; ++i)
   {
      for (int j = 0; j < 8 ; ++j)
      {
         if(ar[i+1][j+1]!=br[i+1][j+1]){ans=0;}
      }
   }
   if(ans==1)
   {
      return true ; 
   }
   else
   {
      return false ; 
   }
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int n = 8 ; 
      for (int i = 0; i < n ; ++i)
      {
         string s ;
         cin >> s ;
         int j = 0 ; 
         for(auto c : s )
         {
            int x = c=='.' ? 0 : 1 ; 
            ar[i+1][j+1] = x ; 
            j++ ; 
         }
      }
      int a,b ; 
      for(int i=1;i<=n;i++)
      {
         for(int j=1;j<=n;j++)
         {
            if(valid(i,j))
            {
                a = i ; 
                b = j ; 
            }
         }
      }
      cout << a << " " << b << endl ;
   }
   return 0 ;
}