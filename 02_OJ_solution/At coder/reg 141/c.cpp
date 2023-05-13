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
int ar[25],n ; 
string s,kk ; 
bool valid(int r,int b)
{
   string seg = "" ; 
   for(int i=1;i<=r;i++)
   {
      char c = ar[i]+'0' ; 
      seg+=c ; 
   }
   string ans="" ; 
   while(b--)
   {
      ans+=seg ;
   }
   kk = ans ; 
   if(ans<=s){return true ;}
   return false ; 
}
string calco(int range)
{
   std::vector < int > br(25,0) ;
   int block = n/range ; 
   if(valid(range,block))
   {
      return kk ; 
   }
   for(int i=1;i<=range;i++)
   {
      int j = i ; 
      int as = i==range ? ar[i]-1 : ar[i] ; 
      while(j<=n)
      { 
         br[j]=as ; 
         j+=range ; 
      }
   }
   string ans = "" ; 
   for(int i=1;i<=n;i++)
   {
      char c = br[i]+'0' ; 
      ans+=c ; 
   }
   return ans ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      cin >> s ;
      n = s.size() ; 
      int idx = 1 ; 
      for(auto c : s )
      {
         int x = c-'0' ; 
         ar[idx++] = x ; 
      }

      string ans = "" ; 
      for(int i=1;i<=(n/2);i++)
      {
         string temp = calco(i) ; 
         ans = max(ans,temp) ; 
      }
      if(ans[0]=='0')
      {
         n-- ; 
         ans = "" ; 
         while(n--)
         {
            ans+='9' ; 
         }
      }
      cout << ans << endl ;
   }
   return 0 ;
}