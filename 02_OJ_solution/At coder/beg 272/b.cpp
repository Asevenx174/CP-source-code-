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
const ll maxx = 100+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
bool used[maxx][maxx] ; 
int main()
{
   debugMode();
   int n,m ; 
   cin >> n >> m ;
   for (int i = 0; i < m ; ++i)
   {
      int k ;
      cin >> k ;
      for (int j = 0; j < k ; ++j )
      {
         int x ;
         cin >> x ;
         used[i][x] = true ; 
      }
   }
   int f = 1 ; 
   for(int i=1;i<=n;i++)
   {
      for(int j=i+1;j<=n;j++)
      {
         int flag = 0 ; 
         for (int p = 0; p < m  ; ++p)
         {
            if(used[p][i] && used[p][j]){flag=1;}
         }
         if(!flag){f=0;break;}
      }
   }
   if(f)
   {
      cout << "Yes" << endl ; 
   }
   else
   {
      cout << "No" << endl ;
   }
   return 0 ;
}