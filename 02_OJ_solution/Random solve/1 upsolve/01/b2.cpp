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
map < int ,int > pq ; 
int n,k,need ; 
bool valid(int mex)
{
   need = 0 ; 
   for (int i = 0; i < mex ; ++i)
   {
      if(pq[i]==0){need++;}
   }
   int taken = mex-need ; 
   int can = min(k,n-taken) ; 
   if(can>=need){ return true ; }
   return false ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      pq.clear() ; 
      set < int > s ; 
      cin >> n >> k ; 
      for (int i = 0; i < n ; ++i)
      {
         int x ;
         cin >> x ;
         pq[x]++ ; 
         s.insert(x) ; 
      }
      int l=0,r=n+10,mex=0 ; 
      while(l<=r)
      {
         int mid = (l+r)/2 ; 
         if(valid(mid))
         {
           mex = mid ; 
           l = mid+1 ; 
         }
         else
         {
           r = mid-1 ; 
         }
      }
      bool temp = valid(mex) ; 
      
      // to gain mex we have to convert "need" number of numbers such that total distinct number is min
      int dis = mex ; 
      std::vector < int > v ;
      auto it = s.lower_bound(mex) ;
      while(it!=s.end())
      {
         int x = *it ; 
         v.push_back(pq[x]) ; 
         it++ ; 
      } 
      sort(v.begin(),v.end()) ; 
      for(auto x : v )
      {
         if(x<=need)
         {
            need-=x ; 
         }
         else
         {
            dis++ ; 
         }
      }
      int ans = dis-mex ; 
      cout << ans << endl ;
   }
   return 0 ;
}