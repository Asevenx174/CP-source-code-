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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],pre[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int n,k ;
      cin >> n >> k ;
      string s ;
      cin >> s ;
      int idx = 1 ,sum=0 ; 
      for(auto c : s )
      {
         int x = c=='W' ? 0 : 1 ; 
         ar[idx] = x ; 
         sum+=x ;
         pre[idx] = sum ; 
         idx++ ;  
      }
      int ans = mod ; 
      for(int i=k;i<=n;i++)
      {
         int have = pre[i]-pre[i-k] ;
         ans = min(ans,k-have) ;  
      }
      cout << ans << endl ;
   }
   return 0 ;
}
