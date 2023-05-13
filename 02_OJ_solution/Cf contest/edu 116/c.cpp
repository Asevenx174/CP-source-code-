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
const ll maxx = 4e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
std::vector < vector < int > > v ;
int arr[maxx],xrr[maxx],krr[maxx] ; 
vector < int > p[maxx] ; 
int main()
{
   debugMode();
   map < int ,int > pq ; 
   set < int > s ; 
   int n,q ;
   cin >> n >> q ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> arr[i+1] ; 
      s.insert(arr[i+1]) ; 
   }
   for (int i = 0; i < q ; ++i)
   {
      cin >> xrr[i+1] >> krr[i+1] ;  
      s.insert(xrr[i+1]) ; 
   }
   int idx = 1 ; 
   for(auto x : s )
   {
      pq[x] = idx++ ; 
   }
   for(int i=1;i<=n;i++)
   {
      int x = arr[i] ; 
      x = pq[x] ; 
      p[x].push_back(i) ; 
   }
   for(int i=1;i<idx;i++)
   {
      v.push_back(p[i]) ; 
   }
   for (int i = 0; i < q ; ++i)
   {
      int x = xrr[i+1] , k = krr[i+1] ; 
      x = pq[x] ; 
      //cout << x << " " << k << endl ;
      if(p[x].size()<k)
      {
         cout << "-1" << endl ;
      }
      else
      {
         cout << v[x-1][k-1] << endl ;
      }
   }
   return 0  ;
}