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
using namespace std ;
typedef long long ll ;
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=1e18+10;
int arr[maxx];
int main()
{
   int n,k ;
   cin >> n >> k ;
   for(int i=1;i<=n;i++)
   {
       string s ;
       cin >> s ;
       int ans = 0 ;
       for(auto c : s )
       {
           ans = ans << 1 ;
           ans+=((c-'0')&1);
       }
       arr[i]=ans ;
   }
   int ans = mod ;
   for(int i=1;i<=n;i++)
   {
       for(int j=i+1;j<=n;j++)
       {
           ans = min(ans,__builtin_popcount(arr[i]^arr[j]));
       }
   }
   cout << ans << endl;
   return 0 ;
}
