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
const ll maxx = 2e5+10,mod=1e9+7,imax=1e18+10;
vector < int > g[maxx];
int sub[maxx];
void dfs(int p,int c)
{
    int ans = 1 ;
    for(auto x : g[c] )
    {
        if(x!=p)
        {
            dfs(c,x);
            ans+=sub[x];
        }
    }
    sub[c]=ans ;
}
int main()
{
   ll n ;
   cin >> n ;
   for(int i=2;i<=n;i++)
   {
       ll x ;
       cin >> x ;
       g[x].push_back(i);
       g[i].push_back(x);
   }
   dfs(0,1);
   for(int i=1;i<=n;i++)
   {
       if(i!=1){cout << " " ;}
       cout << sub[i]-1 ;
   }
   cout << endl;
   return 0 ;
}
