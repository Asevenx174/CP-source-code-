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
int a[maxx],b[maxx];
map < int ,int > pq,mn ;
int arr[2*maxx+10];
int main()
{
   vector < int > v ;
   int n ;
   cin >> n ;
   for(int i=1;i<=n;i++)
   {
       cin >> a[i] >> b[i] ;
       v.push_back(a[i]);
       v.push_back(b[i]);
   }
   int idx = 1 ;
   sort(v.begin(),v.end());
   while(idx<=v.size())
   {
       pq[ v[idx-1] ]=idx;
       mn[idx] = v[idx-1] ;
       idx++;
   }
   for(int i=1;i<=n;i++)
   {
       int l = pq[ a[i] ] , r = pq[ b[i] ] ;
       arr[l]++;
       arr[r+1]--;
   }
   ll ans = 0 , sum = 0 ;
   for(int i=1;i<=2*maxx;i++)
   {
       sum+=arr[i] ;
       ans = max(ans,sum);
   }
   cout << ans << endl;
   return 0 ;
}
