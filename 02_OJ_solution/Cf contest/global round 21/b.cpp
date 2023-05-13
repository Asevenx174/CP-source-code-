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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n,z=0,f=0 ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         ll x ;
         cin >> x ;
         ar[i+1] = x ; 
         if(x==0)
         {
            z = 1 ; 
         }
         else
         {
            f = 1 ; 
         }
      }
      int ans = 0 ; 
      if(f==0)
      {
         ans = 0 ; 
      }
      else if(z==0)
      {
         ans = 1 ; 
      }
      else
      {
         int l = 0 ; 
         int r = n+1 ; 
         while(l+1<=n && ar[l+1]==0)
         {
            l++ ; 
         }
         while(r-1>0 && ar[r-1]==0)
         {
            r-- ; 
         }
         l++;
         r--;
         z = 0 ; 
         while(l<=r)
         {
            if(ar[l]==0){z=1;}
            l++ ; 
         }
         if(z==1)
         {
            ans = 2 ; 
         }
         else
         {
            ans = 1 ; 
         }
      }
      cout << ans << endl ;
   }
   return 0 ;
}