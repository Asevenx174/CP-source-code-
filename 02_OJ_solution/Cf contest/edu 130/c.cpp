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
int ar[maxx+10],br[maxx+10],n ; 
int main()
{
   debugMode();
   map < char ,int > pq ; 
   char cc = 'a' ; 
   int idx = 1 ; 
   while(cc<='z')
   {
      pq[cc] = idx ; 
      cc++ ; 
      idx++ ; 
   }
   int test ;
   cin >> test ;
   while(test--)
   {
      std::vector< int > p,q ;
      cin >> n ;
      string a,b ;
      cin >> a >> b ; 
      idx = 1 ; 
      for(auto c : a )
      {
         ar[idx] = pq[c] ; 
         if(ar[idx]!=2)
         {
            p.push_back(ar[idx]) ; 
         }
         idx++ ; 
      }
      idx = 1 ; 
      for(auto c : b )
      {
         br[idx] = pq[c] ; 
         if(br[idx]!=2)
         {
            q.push_back(br[idx]) ; 
         }
         idx++ ; 
      }
      if(p.size()!=q.size())
      {
         cout << "NO" << endl ; continue ; 
      }
      auto it = p.begin() ; 
      auto lt = q.begin() ; 
      int ans = 1 ; 
      while(1)
      {
         if(it==p.end()){break;}
         if((*it)!=(*lt)){ans=0;}
         it++ ; 
         lt++ ; 
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