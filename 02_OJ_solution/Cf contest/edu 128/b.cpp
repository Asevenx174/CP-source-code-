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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[10][10],n,m ; 
std::vector < pii > rob ;
bool valid(pii s)
{
   int r = s.ff-1 ; 
   int c = s.ss-1 ;
   for(auto p : rob )
   {
      int a = p.ff-r ; 
      int b = p.ss-c ; 
      if(min(a,b)<1 || a>n || b>m ){return false ;}
   }
   return true ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      rob.clear() ; 
      cin >> n >> m ; 
      for (int i = 0; i < n ; ++i)
      {
         string s ;
         cin >> s ;
         int j = 0 ; 
         for(auto c : s )
         {
            int x = c=='R' ? 1 : 0 ; 
            ar[i+1][j+1] = x ; 
            if(x==1)
            {
               rob.push_back({i+1,j+1}) ; 
            }
            j++ ; 
         }
      }
      int ans = 0 ; 
      for(auto p : rob )
      {
         if(valid(p))
         {
           ans = 1 ; 
         }
      }
      if(ans==1)
      {
         cout << "YES" << endl ;
      }
      else
      {
         cout << "NO" << endl ;
      }
   }
   return 0 ;
}