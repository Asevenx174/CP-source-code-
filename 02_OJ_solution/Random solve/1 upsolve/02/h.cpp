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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n,br[maxx+10] ; 
bool used[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      ms(used,false) ; 
      int n ;
      cin >> n ;
      string s ;
      cin >> s ;
      int idx = 1,k=0,l=0,r=0,lim ; 
      for(auto c : s )
      {
         int x = c=='1' ? 1 : 0 ; 
         ar[idx] = x ; 
         if(x==1)
         {
            if(r==0)
            {
               r = idx ; 
            }
            br[++k]=idx ; 
            used[idx] = true ; 
         }
         idx++ ;
      }
      lim = n-(k-2)/2 ;
      //cout << lim << endl ; 
      l = r ; 
      if(l<0)
      {
         l = n ; 
      }
      if(k<2 || k%2==1)
      {
         cout << "NO" << endl ; continue ; 
      }
      idx = 1 ; 
      std::vector < int > ans ;
      do
      {
         if(idx%2==1)
         {
            ans.push_back(r) ; 
            //cout << " " << r ; 
            r++ ; 
            while(!used[r])
            {
               //cout << " " << r ;
               ans.push_back(r) ; 
               r++ ; 
            }
            //cout << endl ;
         }
         else
         {
            l-- ; 
            if(l<1){l=n;}
            while(!used[l])
            {
               ans.push_back(l) ; 
               //cout << " " << l ;
               l-- ; 
               if(l<1){l=n;}
            }
            //cout << endl ;
            if(ans.size()==lim-1)
            {
               //cout << "? " << l << endl ;
               ans.push_back(l) ; 
            }
         }
         idx++ ; 
      }
      while(ans.size()<lim);
      vector < pii > pq ; 
      l=2,r=k ; 
      while(l<r)
      {
         pq.push_back({br[l],br[r]}) ;
         l++;
         r--; 
      }
      idx = 0 ; 
      for(int i=1;i<ans.size();i++)
      {
         pq.push_back({ans[i-1],ans[i]}) ; 
      }
      cout << "YES" << endl ;
      for(auto x : pq )
      {
         cout << x.ff << " " << x.ss << endl ;
      }
   }
   return 0 ;
}