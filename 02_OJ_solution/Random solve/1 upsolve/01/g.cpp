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
const ll maxx = 1010 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
bool used[maxx+10][maxx+10];
int main()
{
   debugMode();
   int n,m,qes,ic=0 ;
   cin >> n >> m >> qes ; 
   for (int i = 0; i < n ; ++i)
   {
      string s ;
      cin >> s ;
      int j = 0 ; 
      for(auto c : s )
      {
         bool as = c=='*' ? true : false ;
         if(as){ic++;} 
         used[i+1][j+1]=as ; 
         j++ ; 
      }
   }
   // we have ic and assigned array 

   int ans = 0 ;
   int r=1,c=1 ; 
   int p,q ;
   cin >> p >> q ;


    r = n ; 
    c = ic/n ; 
    int ex = ic%n ; 
    if(ex>0)
    {
      r = ex ; 
      c++ ; 
    }

      if(used[p][q])
      {
         ic-- ; 
         if( ! (q<c || (q==c && p<=r)) )
         {
            ans-- ;
         } 
      }
      else
      {
         ic++ ;
         if( !(q<c || (q==c && p<=r)) )
         {
            ans++ ;
         }
      }
      used[p][q]=!used[p][q] ;

 




   qes-- ; 
   
   int temp = ic ;  
   while(temp>0)
   {
      temp-- ; 
      if(!used[r][c]){ans++;}
      r++ ; 
      if(r>n){c++;}
   }
   cout << ans << endl ;

       r = n ; 
       c = ic/n ; 
       ex = ic%n ; 
       if(ex>0)
       {
         r = ex ; 
         c++ ; 
       }


   while(qes>0)
   {
      qes-- ; 
      int x,y ;
      cin >> x >> y ; 
      if(used[x][y])
      {
         ic-- ; 
         if( ! (y<c || (y==c && x<=r)) )
         {
            ans-- ;
         } 
      }
      else
      {
         ic++ ;
         if( !(y<c || (y==c && x<=r)) )
         {
            ans++ ;
         }
      }
      used[x][y]=!used[x][y] ; 
      cout << ans << endl ;
      

       r = n ; 
       c = ic/n ; 
       ex = ic%n ; 
       if(ex>0)
       {
         r = ex ; 
         c++ ; 
       }
   }
   return 0 ;
}