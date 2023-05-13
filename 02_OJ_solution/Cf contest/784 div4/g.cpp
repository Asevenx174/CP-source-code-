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
const ll maxx = 55 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx][maxx] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int n,m ;
      cin >> n >> m ;
      for (int i = 0; i < n ; ++i)
      {
         string s ;
         cin >> s ;
         int j = 0 ;
         for(auto c : s )
         {
            int x = 0 ;
            if(c=='*'){x=1;}else if(c=='o'){x=2;}
            ar[i+1][j+1] = x ; 
            j++ ; 
         }
      }
      for(int c=1;c<=m;c++)
      {
         int r = n ; 
         int p=-1,q=-1 ; 
         while(r>0)
         {
            int x = ar[r][c] ; 
            if(x==0)
            {
               if(p==-1){p=r,q=c;}
            }
            else if(x==1)
            {
               if(p!=-1)
               {
                  ar[p][c]=1 ; 
                  ar[r][c]=0 ; 
                  p-- ; 
               }
            }
            else
            {
               p=-1 ; 
            }
            r-- ; 
         }
      }
      for(int i=1;i<=n;i++)
      {
         for(int j=1;j<=m;j++)
         {
            int x = ar[i][j] ; 
            char c = '.' ; 
            if(x==1)
            {
               c = '*' ; 
            }
            else if(x==2)
            {
               c = 'o' ; 
            }
            cout << c ; 
         }
         cout << endl ;
      }
   }
   return 0 ;
}