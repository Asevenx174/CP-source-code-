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
ll arr[maxx];
map < ll ,ll > pq ;
int main()
{
   ll n,k ;
   cin >> n >> k ;
   for(int i=1;i<=n;i++)
   {
       cin >> arr[i] ;
   }
   ll l=1,r=1,co=1;
   pq[arr[1]]++;
   while(co<=k && r<n)
   {
       r++;
       if(pq[arr[r]]==0)
       {
           co++;
       }
       pq[arr[r]]++;
   }
   ll ans = n*(n+1);
   ans = ans >> 1 ;
   if(co<=k)
   {
       cout << ans << endl ; return 0 ;
   }
  // ans-=(n-r+1);
   while(co>k)
   {
       while(co>k)
       {
           ans-=(n-r+1);
           if(pq[arr[l]]==1){co--;}
           pq[arr[l]]--;
           l++;
       }
       while(co<=k && r<n)
       {
           r++;
           if(pq[arr[r]]==0)
           {
              co++;
           }
           pq[arr[r]]++;
       }
   }
   cout << ans << endl;
   return 0 ;
}
