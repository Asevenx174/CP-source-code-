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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int pre[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      set < int > s ; 
      map < int ,int > f ; 
      int n,k ;
      cin >> n >> k ;
      for (int i = 0; i < n ; ++i)
      {
         int x ;
         cin >> x ;
         f[x]++ ; 
         s.insert(x) ; 
      }
      int idx = 0 ; 
      for(auto x : s )
      {
          if(f[x]>=k)
          {
             pre[++idx]=x ; 
          }
      }
      int l=0,r=0 ; 
      int ans = -1 ; 
      int i = 1 ; 
      while(i<=idx)
      {
         int a = pre[i] ; 
         int b = a ; 
         while(i+1<=idx && pre[i]+1==pre[i+1])
         {
             b = pre[i+1] ; 
             i++ ; 
         }
         if(b-a>ans)
         {
            ans = b-a ; 
            l = a ; 
            r = b ; 
         }
         i++;
      }
      if(ans==-1){cout << ans << endl ; continue ; }
      cout << l << " " << r << endl ;
   }
   return 0 ;
}