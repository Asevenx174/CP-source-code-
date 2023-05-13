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
const ll maxx = 200+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int d[maxx+10][maxx+10],n,m,r ; 
int rr[maxx+10] ; 
void calco()
{
   for (int k = 0; k < n; ++k)
   {
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j) 
        {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
   }
}
bool used[maxx+10] ; 
int best = mod ; 
std::vector < int > ans ;
void solve(int u)
{
   int f = 1 ; 
   for(int i=1;i<=r;i++)
   {
      if(used[i]){continue;}
      f = 0 ; 
      used[i] = true ; 
      ans.push_back(i) ; 
      solve(i) ; 
      ans.pop_back() ; 
      used[i] = false ;
   }
   if(f)
   {
      int temp = 0 ; 
      for(int i=1;i<r;i++)
      {
         int a = rr[ ans[i-1] ]; 
         int b = rr[ ans[i] ]  ; 
         temp+=d[a][b] ; 
      }
      best = min(best,temp) ; 
      return ;  
   }
}
int main()
{
   debugMode();
   cin >> n >> m >> r ; 
   for (int i = 0; i <=n; ++i)
   {
      for (int j = 0; j <= m ; ++j)
      {
         int x = i==j ? 0 : mod ; 
         d[i][j] = x ; 
      }
   }
   for (int i = 0; i < r ; ++i)
   {
      cin >> rr[i+1] ; 
   }
   for (int i = 0; i < m  ; ++i)
   {
      int a,b,w ;
      cin >> a >> b >> w ; 
      d[a][b] = w ; 
      d[b][a] = w ; 
   }
   calco() ; 
   for(int i=1;i<=r;i++)
   {
      used[i] = true ; 
      ans.push_back(i) ; 
      solve(i) ; 
      ans.pop_back() ; 
      used[i] = false ; 
   }
   cout << best << endl ;
   return 0 ;
}