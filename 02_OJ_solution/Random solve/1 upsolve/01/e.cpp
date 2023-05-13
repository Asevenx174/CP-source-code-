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
const ll maxx = 5010 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int pr[maxx+10],n ; 
std::vector< int > v[maxx+10],u[maxx+10] ;
int pre[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      ms(pre,0) ; 
      int n ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> pr[i+1] ; 
         v[i+1].clear() ; 
         u[i+1].clear() ; 
      }
      for(int i=n;i>0;i--)
      {
         for(int j=1;j<i;j++)
         {
            if(pr[j]>pr[i])
            {
               u[i].push_back(j) ; 
            }
         }
      }
      int r = n ; 
      while(r>0)
      {
         int l = r-1 ; 
         while(l>0)
         {
            if(pr[l]>pr[r])
            {
               pre[l]++ ; 
            }
            l-- ; 
         }
         r-- ; 
      }
      int sum = 0 ; 
      for(int i=n;i>0;i--)
      {
         sum+=pre[i] ; 
         pre[i] = sum ; 
      }
      for(int i=1;i<=n;i++)
      {
         cout << i << " " << pre[i] << endl ;
         for(int j=i+1;j<=n;j++)
         {
            if(pr[i]<pr[j])
            {
               v[i].push_back(j) ; 
            }
            
         }
      }
      //cout << pre[1]-pre[4] << endl ;
      sum = 0 ;
      int a=1 ; 
      while(a<=n)
      {
         for(auto c : v[a] )
         {
            auto it = upper_bound(u[c].begin(),u[c].end(),a) ; 
            ll sub = u[c].end()-it ; 
            ll add = pre[a+1]-pre[c]-sub ; 
            cout << a << " " << c << " " << add+sub << " "  << add << endl ;
            sum+=add ; 
         }
         a++ ; 
      }
      cout << sum << endl ;
   }
   return 0 ;
}