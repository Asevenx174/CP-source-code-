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
const ll maxx = (1<<17)+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0,lim=17;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int dp[maxx+10][lim+10],ex[lim+10],a[maxx+10]; 
int main()
{
   debugMode();
   ll mul = 1 ; 
   for(int i=0;i<22;i++)
   {
      ex[i] = mul ; 
      mul = mul*2 ; 
   }
   int test ;
   cin >> test ;
   while(test--)
   {
     int l,r ;
     cin >> l >> r ; 
     int n = r-l+1 ; 
     for(int i=1;i<=n;i++)
     {
       cin >> a[i] ; 
     }
     for(int i=1;i<=n;i++)
     {
      for(int j=0;j<=lim+2;j++)
      {
        dp[i][j] = 0 ;
        int temp = ex[j] ; 
        if(a[i]&temp)
        {
          dp[i][j]++;
        }
        dp[i][j]+=dp[i-1][j] ; 
      }
     }
     int ans = 0 ; 
     for(int j=0;j<18;j++)
     {
       int one = dp[n][j] ; 
       if(one>(n-one))
       {
         ans+=ex[j]  ;
       }
     }
     cout << ans << endl ;
   }
   return 0 ;
}