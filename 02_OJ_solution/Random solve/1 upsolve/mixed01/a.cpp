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
ll ar[maxx+10] ; 
int main()
{
   debugMode();
   ll n,p ; 
   cin >> n >> p ; 
   string s ;
   cin >> s ;
   int idx = 1 ; 
   for(auto c : s )
   {
      int x = c-'0' ; 
      ar[idx] = x ; 
      idx++ ; 
   }
   if(p==2 || p==5)
   {
      ll ans = 0 ; 
      for(int i=1;i<=n;i++)
      {
         if(ar[i]%p==0)
         {
            ans+=i ; 
         }
      }
      cout << ans << endl ; return 0 ; 
   }
   ll mul = 1 ; 
   for(int i=n;i>0;i--)
   {
      ar[i] = (ar[i]*mul)%p ; 
      mul = (mul*10LL)%p ; 
   }
   map < int , int > pq ; 
   pq[0] = 1 ; 
   ll pre = 0 ; 
   ll ans = 0 ; 
   for(int i=1;i<=n;i++)
   {
      pre+=ar[i] ;
      pre = pre%p ;  
      ll k = 0 ; 
      while(p*k<=pre)
      {
         ll sub = pre-(p*k) ; 
         ans+=pq[sub] ; 
         k++ ; 
      }
      pq[pre]++ ; 
   }
   cout << ans << endl ;
   return 0 ;
}