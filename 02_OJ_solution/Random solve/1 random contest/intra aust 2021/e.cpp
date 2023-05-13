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
const ll maxx = 5e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int dp[maxx+10][50] ; 
int main()
{
   debugMode();
   vector < int > lim(50,0) ; 
   char cc = 'a' ; 
   int idx = 1 ;
   map < char ,int > ci ; 
   while(cc<='z')
   {
      ci[cc++]=idx++ ; 
   }
   string s,t ;
   cin >> s >> t ; 
   int n = s.size() ; 
   std::vector< int > v[50] ; 
   idx = 1 ; 
   for(auto c : s )
   {
      int x = ci[c] ; 
      v[x].push_back(idx) ;
      dp[idx][x]=1 ; 
      int k = 1 ; 
      while(k<=26)
      {
         dp[idx][k]+=dp[idx-1][k] ; 
         k++ ; 
      }
      idx++ ;  
   }
   idx = 1 ; 
   for(auto c : t )
   {
      int f = c-'0' ; 
      lim[idx++]=f ; 
   }
   ll l=1,r=1,ans=n*(n+1) ;
   ans = ans/2LL ; 
   while(r<=n)
   {
      int x = ci[s[r-1]] ; 
      if(lim[x]==0){r++;continue;}
      int taken = dp[r][x]-dp[l-1][x] ; 
      if(taken>lim[x])
      {
         auto it = lower_bound(v[x].begin(),v[x].end(),l);
         ll temp = *it+1 ; 
         ll a = temp-l ; 
         ll b = n-r+1 ;
        // cout << a << " " << b << " " << r << endl ; 
         ans-=(a*b) ;  
         l = temp ; 
      } 
      r++ ; 
   }
   cout << ans << endl ;
   return 0 ;
}