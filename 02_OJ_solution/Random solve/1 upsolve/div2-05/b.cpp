#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>

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
ll ar[maxx+10],br[maxx+10],n,cr[maxx+10],mx[maxx+10],mn[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      set < ll > s ; 
      std::vector < ll > a,b ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ;
         a.push_back(ar[i+1]) ;  
         cr[i+1] = 0 ;  
         s.insert(i+1) ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         cin >> br[i+1] ; 
         b.push_back(br[i+1]) ; 
      }
      for(int i=1;i<=n;i++)
      {
         auto it = lower_bound(b.begin(),b.end(),ar[i]) ; 
         mn[i] = *it-ar[i] ; 
      }
      ar[n+1] = mod ; 
      for(int i=n;i>0;i--)
      {
         auto it = lower_bound(b.begin(),b.end(),ar[i+1]) ; 
         ll idx = it-b.begin()+1 ; 
         auto lt = s.find(idx) ; 
         if(lt!=s.end())
         {
            s.erase(lt) ; 
         }
         lt = s.end() ; 
         ll sum = br[i] ; 
         if(!s.empty())
         {
            lt-- ; 
            sum = max(sum,br[*lt]) ; 
         }
         mx[i] = sum-ar[i] ; 
      }
      for(int i=1;i<=n;i++)
      {
         if(i>1){cout << " " ;}
         cout << mn[i] ; 
      }
      cout << endl ;
      for (int i = 1 ; i <= n ; ++i)
      {
         if(i>1){cout << " " ;}
         cout << mx[i] ;
      }
      cout << endl ;
   }
   return 0 ;
}