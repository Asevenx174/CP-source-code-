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
ll ar[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      std::vector< int > v ;
      ll n,m ;
      cin >> n >> m ;
      ll sum = 0 ; 
      for (int i = 0; i < n ; ++i)
      {
          cin >> ar[i] ;
          v.push_back(ar[i]) ;
      }
      sort(v.begin(),v.end()) ; 
      ll p = 0,f=1 ; 
      for(int i=1;i<n;i++)
      {
         ll g = max(v[i],v[i-1]) ;
       //  cout << p << " " << p+g+1 << endl ;
         p+=(g+1) ; 
      }
      p+=(max(v[n-1],v[0])+1) ; 
      if(p>m)
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