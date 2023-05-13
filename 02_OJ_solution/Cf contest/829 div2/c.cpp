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
int ar[maxx+10],n,br[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      std::vector < int > v[5] ;
      int n,sum=0 ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
         sum+=ar[i+1] ; 
         int x = ar[i+1] == 1 ? 1 : 0 ; 
         v[x].push_back(i+1) ; 
         br[i+1] = 0 ; 
      }
      if(n%2==1)
      {
         cout << "-1" << endl ; continue ; 
      }
      if(sum==0)
      {
         cout << "1 " << n << endl ; continue ; 
      }
      sort(v[0].begin(),v[0].end(),greater<int>()) ;
      sort(v[1].begin(),v[1].end(),greater<int>()) ; 
        int idx = sum > 0 ? 0 : 1 ;
         sum = sum/2 ; 
         auto it = v[idx].begin() ; 
         int p = mod ; 
         while(sum--)
         {
            while(1)
            {
               int x = *it ; 
               if(p-1==x){it++;continue;}
               br[*it] = 1 ; 
               p = *it ; 
               it++ ; 
               break ;
            }
         }
        // continue ; 
      vector < pii > ans ; 
      for(int i=n;i>0;i--)
      {
         if(br[i]==1)
         {
            ans.push_back({i-1,i}) ; 
         }
         else
         {
            ans.push_back({i,i}) ; 
         }
      }
      reverse(ans.begin(),ans.end()) ; 
      cout << ans.size() << endl ; 
      for(auto x : ans )
      {
         cout << x.ff << " " << x.ss << endl ;
      }
   }
   return 0 ;
}