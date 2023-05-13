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
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      map < char ,int > p,f ; 
      int n,m,k ;
      cin >> n >> m >> k ; 
      string a,b ;
      cin >> a >> b ; 
      for(auto c : a )
      {
         f[c]++ ; 
         p[c] = 0 ; 
      }
      for(auto c : b )
      {
         f[c]++ ; 
         p[c] = 1 ; 
      }
      set < char > s ; 
      char cc = 'a' ; 
      while(cc<='z')
      {
         if(f[cc]>0)
         {
            s.insert(cc) ; 
         }
         cc++ ; 
      }
      string ans = "" ; 
      auto it = s.begin() ; 
      int lim = k ; 
      std::vector <  int > t (5,0) ;
      while(it!=s.end())
      {
         char c = *it ; 
         int x = p[c] ; 
         if(f[c]<lim)
         {
            t[x]=f[c] ;
            t[!x]=0 ;  
            while(f[c]--)
            {
               ans+=c ; 
            }
         }
         else if(f[c]==k)
         {

         }
         else
         {

         }
      }
   }
   return 0 ;
}