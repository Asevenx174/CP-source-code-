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
const ll maxx = 110 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],br[maxx+10] ; 
int f[maxx][maxx],l[maxx][maxx] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      ms(f,0) ; 
      ms(l,0) ; 
      std::vector < pii > ans ;
      vector < int > b,a ; 
      int n ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
         a.push_back(ar[i+1]) ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         cin >> br[i+1] ; 
         b.push_back(br[i+1]) ; 
         f[ ar[i+1] ][ br[i+1] ]++ ; 
      }
     
      sort(b.begin(),b.end()) ; 
      sort(a.begin(),a.end()) ;
      auto it = a.begin() ; 
      auto lt = b.begin() ; 
      int temp = n ; 
      while(temp--)
      {
         int x = *it ; 
         int y = *lt ; 
         l[x][y]++ ; 
         it++ ; 
         lt++ ; 
      }
      int flag = 0 ; 
      for (int i = 0; i < n ; ++i)
      {
         int x = ar[i+1] ; 
         int y = br[i+1] ; 
         if(f[x][y]!=l[x][y]){flag=1;}
      }
      if(flag==1){cout << "-1" << endl ; continue ; }
      it = a.begin() ; 
      lt = b.begin() ; 
      for(int k=1;k<n;k++)
      {
         int x = *it ; 
         int y = *lt ; 
         int j=k+1 ; 
         while(j<=n)
         {
            if(ar[j]==x && br[j]==y)
            {
               break ; 
            }
            j++ ; 
         }
         if(j<=n)
         {
            ans.push_back({k,j}) ;
            swap(ar[k],ar[j]) ; 
            swap(br[k],br[j]) ; 
         }
         it++ ;
         lt++ ; 
      }
      cout << ans.size() << endl ;
      for(auto x : ans )
      {
         cout << x.ff << " " << x.ss << endl ;
      }
   }
   return 0 ;
}