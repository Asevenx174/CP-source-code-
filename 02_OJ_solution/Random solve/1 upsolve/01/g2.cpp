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
bool used[maxx+10][maxx+10] ;
int rx,ry,n,m ;
void update(int ic)
{
   rx = n ;
   int ex = ic%n ; 
   if(ex>0)
   {
      rx = ex ; 
   } 
   if(ic%n==0)
   {
      ry = ic/n ;  
   }
   else
   {
      ry = (ic/n)+1 ;
   }
   return ;  
}
int main()
{
   debugMode();
   int qes,ic=0 ;
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
   int temp = ic , cost = 0 ; 
   int r=1,c=1 ; 
   while(temp--)
   {
      if(!used[r][c]){cost++;}
      r++ ; 
      if(r>n){r=1,c++;}
   }
   while(qes--)
   {
      int x,y,con=0 ; 
      cin >> x >> y ; 
      update(ic) ; 
      //cout << rx << " " << ry << "  " << ic << endl ;
      if(used[x][y])
      { 
         if(used[rx][ry])
         {
             if(x==rx && y==ry)
             {
                 
             }
             else if( !( (y<ry) || (y==ry && x<=rx) ) )
             {
                 
             }
             else
             {
                 cost++ ; 
             }
         }
         else
         {
             if( !( (y<ry) || (y==ry && x<=rx) ) )
             {
                 cost-- ; 
             }
         }
         ic-- ; 
      }
      else
      {
         // . --- * 
         ic++ ; 
         update(ic);
         if( !( (y<ry) || (y==ry && x<=rx) ) )
         {
            cost++ ; 
         }
         if(used[rx][ry])
         {
            cost-- ; 
         }
      }
      used[x][y]=!used[x][y] ; 
      cout << cost << endl ;
   }
}