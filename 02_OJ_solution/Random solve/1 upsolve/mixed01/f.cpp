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
const ll maxx = 60 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int fx[]={0,0,1,-1},fy[]={1,-1,0,0};
int r,c,ar[maxx+10][maxx+10] ;
int dp[maxx+10][maxx+10] ; 
int main()
{
   debugMode();
   ll sum = 0 ; 
   cin >> r >> c ; 
   for (int i = 0; i < r ; ++i)
   {
      string s ;
      cin >> s ;
      int j = 0 ; 
      for(auto c : s )
      {
         int x = c=='.' ? 0 : 1 ;
         if(x==0){sum++;}
         ar[i+1][j+1] = x ; 
         j++ ; 
      }
   }
   ms(dp,mod) ; 
   queue < pii > q ; 
   q.push({1,1}) ; 
   dp[1][1]=1 ; 
   while(!q.empty())
   {
      pii p = q.front() ; q.pop() ; 
      for (int i = 0; i < 4 ; ++i)
      {
         int x = p.ff+fx[i] ; 
         int y = p.ss+fy[i] ; 
         if(min(x,y)>0 && x<=r && y<=c && (dp[x][y]>dp[p.ff][p.ss]+1) && ar[x][y]==0)
         {  
            dp[x][y]=dp[p.ff][p.ss]+1 ; 
            q.push({x,y}) ; 
         }
      }
   }
   if(dp[r][c]==mod)
   {
      cout << "-1" << endl;
   }
   else
   {
      ll ans = sum-dp[r][c] ; 
      cout << ans << endl ;
   }
   return 0 ;
}