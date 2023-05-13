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
const ll maxx = 1010 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
string s[maxx+10];
set < string > p[maxx+10],q[maxx+10];
int dp[maxx+10];
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      ms(dp,0) ; 
      int n,m ;
      cin >> n >> m ;
      for (int i = 0; i < m+5; ++i)
      {
         p[i].clear() ; 
         q[i].clear() ; 
      }
      for(int i=1;i<=n;i++){cin>>s[i];}
      string k ;
      cin >> k ;
      for(int i=1;i<=n;i++)
      {
         string temp = s[i] ; 
         for(int j=1;j<m;j++)
         {
            string a = "" ; 
            a+=temp[j-1] ; 
            a+=temp[j] ; 
            p[j].insert(a);
            
            if(j+1<m)
            {
               string b = "" ; 
               b+=temp[j-1] ; 
               b+=temp[j];
               b+=temp[j+1];
               q[j].insert(b) ; 
            }
         }
      }
      dp[0]=1 ; 
      for(int i=2;i<=m;i++)
      {
         string a = "" ; 
         a+=k[i-2] ; 
         a+=k[i-1] ; 
         if(dp[i-2]==1 && p[i-1].find(a)!=p[i-1].end())
         {
            dp[i] = 1 ; 
         }
         if(i>2)
         {
            a = "" ; 
            a+=k[i-3] ; 
            a+=k[i-2] ;
            a+=k[i-1] ; 
            if(dp[i-3]==1 && q[i-2].find(a)!=q[i-2].end())
            {
               dp[i] = 1 ; 
            }
         }
         cout << i << " " << dp[i] << endl ;
      }
      if(dp[m]==1)
      {
         cout << "YES" << endl ;
      }
      else
      {
         cout << "NO" << endl ;
      }
   }
   return 0 ;
}