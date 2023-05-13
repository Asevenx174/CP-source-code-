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
const ll maxx = 2e5+10,mod=1010,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,k,fr[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      vector < int > q[mod] ; 
      std::vector < vector < int> > v ;
      cin >> n >> k ; 
      v.resize(k+5) ; 
      for (int i = 0; i < n ; ++i)
      {
         ll a ;
         cin >> a ;
         q[a%k].push_back(a) ; 
      }
      for(int i=0;i<k;i++)
      {
         v[i].resize(q[i].size()+5) ; 
         int idx = 0 ;
         for(auto x : q[i] )
         {
            v[i][++idx] = x ; 
         }
         fr[i]=idx ; 
      }
      ll ans = 0 ; 
      int i=k,f=1 ; 
      int co = 2*k ; 
      do
      {
         for(int j=0;j<=i;j++)
         {
            int a=j,b=i-j ; 
            if(a==b)
            {
               while(fr[a]>1)
               {
                  ll x = v[a][fr[a]] ; 
                  ll y = v[a][fr[a]-1] ;  
                  ans+=((x+y)/k) ; 
                 // cout << x << " " << y << endl ;
                  fr[a]-=2 ; 
               }
            }
            else
            {
               while(fr[a]>0 && fr[b]>0)
               {
                  ll x = v[a][fr[a]] ; 
                  ll y = v[b][fr[b]] ;  
                  ans+=((x+y)/k) ;
                  fr[a]--;
                  fr[b]--; 
                  //cout << x << " " << y << endl ;
               }
            }
         }
         if(i+1==2*k)
         {
            i = 0 ; 
         }
         else
         {
            i++ ; 
         }
         co-- ; 
      }
      while(co>0);
      cout << ans << endl ;
   }
   return 0 ;
}