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
const ll maxx = 50+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+5][maxx+4] ; 
int n,m ; 
 queue < pii > q ;
int fx[10] = {1,0,0} ; 
int fy[10] = {0,1,-1} ;   
void make_change(pii p)
{
   int flag = ar[p.ff+1][p.ss]==3 ? 1 : 0 ;

   for (int i = 0; i < 3 ; ++i)
   {
      int x = p.ff+fx[i] ; 
      int y = p.ss+fy[i] ; 
      if(min(x,y)<0 || x>n || y>m || ar[x][y]!=1){continue;}
      if(i==0)
      {
         ar[x][y] = 2 ; 
         q.push({x,y}) ;
      }
      else if(flag)
      {
         ar[x][y] = 2 ; 
         q.push({x,y}) ;
      }
   }
}
int main()
{
   debugMode();
   cin >> n >> m ; 
   for (int i = 0; i < n ; ++i)
   {
      string s ;
      cin >> s ;
      int j = 0 ; 
      while(j<m)
      {
         int temp ;  
         if(s[j]=='.'){temp=1;}else if(s[j]=='V'){temp=2;}else{temp=3;}
         ar[i+1][j+1] = temp ; 
         if(temp==2)
         {
            q.push({i+1,j+1}) ; 
         }
         j++ ; 
      }
   }
   while(!q.empty())
   {
      pii p = q.front() ; q.pop() ; 
      make_change(p) ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      for (int j = 0; j < m ; ++j)
      {
         int temp = ar[i+1][j+1] ;
         char ch ; 
         if(temp==1){ch='.';}else if(temp==2){ch='V';}else{ch='#';}
         cout << ch ;  
      }
      cout << endl ;
   }
   return 0 ;
}