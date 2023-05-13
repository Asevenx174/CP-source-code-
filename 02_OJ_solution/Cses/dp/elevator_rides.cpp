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
const ll maxx = 21 ,mod= (1<<21)+5 ,imax=1e18+10,qq=1,zz=0;
inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll w[maxx+5];
pii best[mod+5];
int main()
{
   debugMode();
   ll n,space ; 
   cin >> n >> space ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> w[i] ; 
   }
   for(int mask = 1 ; mask < (1<<n) ; mask++)
   {
      // mask is set/group of people , lets say 0,2,3
      best[mask]={n+1,0} ; // worst case , need 1 ride for each person 
      for (int p = 0; p < n ; ++p)
      {
         if(mask&(1<<p))/// is person p in group mask/set ?
         {
            pii rest = best[ mask^(1<<p) ]  ; 
            /// apart from person p , take rest of the member as new set rest .
            /// can u add person p in set rest as a last member ??? 
            if(rest.ss+w[p]<=space)
            {
                rest.ss+=w[p] ; 
            }
            else
            {  
                // we need a new ride
                rest.ff++;
                rest.ss=w[p] ; 
            }
            best[mask]=min(best[mask],rest) ;
         }
      }
   }
   cout << best[(1<<n)-1].ff+1 << endl ;
   return 0 ;
}