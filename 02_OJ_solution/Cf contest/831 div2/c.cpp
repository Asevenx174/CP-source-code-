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
int ar[maxx+10],n,f[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      set < int > s ; 
      int a = mod ; 
      int b = 0 ; 
      cin >> n ; 
      for (int i = 0; i < n ; ++i)
      {
         int x ;
         cin >> x ; 
         a = min(a,x) ; 
         b = max(b,x) ; 
         s.insert(x) ; 
         ar[i] = x ; 
      }
      if(s.size()==1)
      {
         cout << "0" << endl ; continue ; 
      }
      else if(s.size()>2)
      {
         std::vector < int > v ; 
         for(auto x : s )
         {
            v.push_back(x) ; 
         }
         int len = s.size(),ans=0 ; 
         for(int i=0;i+2<len;i++)
         {
            int a = v[i] ; 
            int c = v[len-1] ; 
            int b ;
            b = v[i+1] ; 
            int temp = abs(a-c)+min(abs(b-c),abs(b-a)) ; 
            ans = max(ans,temp) ; 
            b = v[len-2] ;
            temp = abs(a-c)+min(abs(b-c),abs(b-a)) ; 
            ans = max(ans,temp) ;  
         }
         cout << ans << endl ; 
         continue ; 
      }
      int ans = abs(a-b)+abs(a-b) ;
      cout << ans << endl ; 
   }
   return 0 ;
}