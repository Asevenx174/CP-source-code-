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
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int n ;
      cin >> n ; 
      string a,b ;
      cin >> a >> b ; 
      string p="",q="" ; 
      std::vector< int > v[10],u[10] ;
      int idx = 1 ; 
      for(auto c : a )
      {
         if(c!='b')
         {
            int x = c=='a' ? 1 : 3 ; 
            v[x].push_back(idx) ; 
            p+=c ; 
         }
         idx++ ; 
      }
      idx = 1 ; 
      for(auto c : b )
      {
         if(c!='b')
         {
            int x = c=='a' ? 1 : 3 ; 
            u[x].push_back(idx) ; 
            q+=c ; 
         }
         idx++ ; 
      }
      if(p!=q){cout << "NO" << endl ; continue ; }
      int ans = 1 ; 
      for(int i=0;i<v[1].size();i++)
      {
         if(v[1][i]>u[1][i]){ans=0;}
      } 
      for(int i=0;i<v[3].size();i++)
      {
         if(v[3][i]<u[3][i]){ans=0;}
      }
      if(ans==0)
      {
         cout << "NO" << endl ;
      }
      else
      {
         cout << "YES" << endl ;
      }
   }
   return 0 ;
}