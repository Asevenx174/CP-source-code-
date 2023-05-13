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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
std::vector< int > v[maxx+10] ;
bool used[maxx+10] ; 
int valid(int idx)
{
   int l = 0 ; 
   int r = v[idx].size()-1 ; 
   int ans = 0 ; 
   while(l<=r)
   {
      int m = (l+r)/2 ; 
      int val = v[idx][m] ; 
      if(used[val])
      {
         l = m+1 ; 
      }
      else
      {
         ans = val ; 
         r = m-1 ; 
      }
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
      set < int > s ; 
      int n ;
      cin >> n ; 
      for(int i=1;i<=n;i++)
      {
         s.insert(i) ; 
         v[i].clear() ;
         used[i] = false ; 
         int k ;
         cin >> k ;
         for(int j=1;j<=k;j++)
         {
            int x ; 
            cin >> x ;
            v[i].push_back(x) ; 
         }
      }
      int idx = 1 ; 
      int f = 1 ; 
      while(idx<=n)
      {
         int val = valid(idx) ; 
         //cout << idx << " " << val << endl ;
         if(val==0)
         {
            if(!s.empty())
            {
               auto it = s.begin() ; 
               cout << "IMPROVE" << endl ;
               cout << idx << " " << *it << endl ; 
               f = 0 ; 
            }
            break ;  
         }
         else
         {
            used[val] = true ; 
            s.erase(s.find(val)) ; 
         }
         idx++ ; 
      }
      if(f)
      {
         cout << "OPTIMAL" << endl ;
      }
   }
   return 0 ;
}