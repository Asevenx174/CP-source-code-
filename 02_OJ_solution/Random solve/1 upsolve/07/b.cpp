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
#define pi                 pair < int ,pii >

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
const ll maxx = 1005 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int aa,bb,ans ; 

int main()
{
   debugMode();
   int test ;
   cin >> test ; 
   while(test--)
   {
      int lx=mod,rx=-mod,ly=mod,ry=-mod ; 
      int n,m ;
      cin >> n >> m ;
      for (int i = 0; i < n ; ++i)
      {
         string s ;
         cin >> s ;
         int j = 0 ; 
         for(auto c : s )
         {
            int x = c=='B' ? 1 : 0 ; 
            if(x==1)
            {
               int p = i+1 ; 
               int q = j+1 ; 
               int pp = p+q ; 
               int qq = q-p ; 
               lx = min(lx,pp) ; 
               rx = max(rx,pp) ; 
               ly = min(ly,qq) ; 
               ry = max(ry,qq) ;
            }
            j++ ; 
         }
      }
   
      aa = 0 ; 
      bb = 0 ; 
      ans = mod ; 
      for(int i=1;i<=n;i++)
      {
         for(int j=1;j<=m;j++)
         {
            int best = 0 ; 
            int ii = i+j ; 
            int jj = j-i ; 
            best = max(best,abs(ii-lx));
            best = max(best,abs(ii-rx));
            best = max(best,abs(jj-ly));
            best = max(best,abs(jj-ry));
            if(best<ans)
            {
               ans = best ; 
               aa = i ; 
               bb = j ; 
            }
         }
      }
      cout << aa << " " << bb << endl ;
   }
   return 0 ;
}