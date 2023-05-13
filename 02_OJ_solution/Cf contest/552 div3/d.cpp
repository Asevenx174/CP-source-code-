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
ll sr[maxx+10],p[maxx+10],q[maxx+10],n ; 
bool valid(ll idx,ll a,ll b)
{
   ll temp = a ;  
   for(int i=1;i<=idx;i++)
   {
      if(sr[i]==1)
      {
         if(a==temp)
         {
            a-- ; 
         }
         else
         {
            if(b>0)
            {
               b--;
               a++;
            }
            else if(a>0)
            {
               a--;
            }
            else
            {
               return false ; 
            }
         }
      }
      else
      {
         if(a>0)
         {
            a-- ; 
         }
         else if(b>0)
         {
            b-- ; 
         }
         else { return false ; }
      }
   } 
   return true ; 
}
int main()
{
   debugMode();
   int sum1=0,sum2=0,a,b ; 
   cin >> n >> b >> a ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> sr[i+1] ; 
   }
   for(int i=1;i<=n;i++)
   {
      if(sr[i]==1)
      {
         sum1++ ; 
      }
      else{sum2++;}
      p[i] = sum1 ; 
      q[i] = sum2 ; 
   }
   ll l=1,r=n,ans=0 ; 
   while(l<=r)
   {
      ll mid = (l+r)/2LL ;
      if(valid(mid,a,b))
      {
         ans = mid ; 
         l = mid+1 ; 
      }
      else
      {
         r = mid-1 ; 
      }
   }
   cout << ans << endl ;
   return 0 ;
}