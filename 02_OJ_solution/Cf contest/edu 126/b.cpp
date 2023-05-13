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
const ll maxx = 100+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
string s[maxx],t[maxx] ; 
int main()
{
   debugMode();
   map < string , int > pq ; 
   int test ;
   cin >> test ;
   int idx = 1 ; 
   while(test--)
   {
     cin >> s[idx] >> t[idx] ; 
     pq[ s[idx] ]++ ; 
     pq[ t[idx] ]++ ; 
     idx++ ; 
   }
   for(int i=1;i<idx;i++)
   {
      string a,b ;
      a = s[i] ; 
      b = t[i] ; 
      int m = 1 ; 
      if(a==b)
      {
         m=2 ; 
      }
      int f = 0 ; 
      if( pq[a]==m  || pq[b]==m ){f=1;}
      if(f==0)
      {
         cout << "No" << endl ;
         return 0 ; 
      }
   }
   cout << "Yes" << endl ; 
   return 0 ;
}