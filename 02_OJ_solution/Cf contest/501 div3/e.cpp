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
const ll maxx = 1010 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int fx[10]={0,-1,0,1} ;
int fy[10]={1,0,-1,0} ; 
int n,m,ar[maxx][maxx],pr[maxx][maxx],pc[maxx][maxx],br[maxx][maxx],cr[maxx][maxx] ; 
bool okk(int a,int b,pii p)
{
   if( !(1<=a && a<=n) || !(1<=b && b<=m) ){ return false ;}
   int l = min(a,p.ff) ; 
   int r = max(a,p.ff) ; 
   int len = r-l+1 ; 
   int have = pr[r][p.ss]-pr[l-1][p.ss] ; 
   if(len!=have){return false ; }

   l = min(b,p.ss) ; 
   r = max(b,p.ss) ; 
   len = r-l+1 ; 
   have = pc[p.ff][r]-pc[p.ff][l-1] ; 
   if(len!=have){return false ; }
   return true ; 
}
bool valid(pii p,int l)
{
    int x = p.ff ; 
    int y = p.ss ; 
    for (int i = 0; i < 4 ; ++i)
    {
       int a = x+fx[i]*l ; 
       int b = y+fy[i]*l ; 
       if(!okk(a,b,p))
       {
          return false ; 
       }
    }
    return true ; 
}
int calco(pii p)
{
   int l=1,r=1005,len=0 ; 
   while(l<=r)
   {
      int mid = (l+r)/2 ; 
      if(valid(p,mid))
      {
         len = mid ; 
         l = mid+1 ; 
      } 
      else
      {
         r = mid-1 ; 
      }
   }
   return len ; 
}
int main()
{
   debugMode();
   std::vector< pii > star ;
   cin >> n >> m ; 
   lp(i,1,n)
   {
      string s ; 
      cin >> s ; 
      int j = 1 ; 
      for(auto c : s )
      {
         int x = c=='*' ? 1 : 0 ; 
         if(x==1)
         {
            star.push_back({i,j}) ; 
         }
         ar[i][j++]=x ; 
      }
   }
   lp(i,1,n)
   {
      int j = 1 ; 
      int sum = 0 ; 
      while(j<=m)
      {
         sum+=ar[i][j] ; 
         pc[i][j]=sum ; 
         j++ ; 
      }
   }
   lp(i,1,m)
   {
      int j = 1 ; 
      int sum = 0 ; 
      while(j<=n)
      {
         sum+=ar[j][i] ; 
         pr[j][i]=sum ; 
         j++ ; 
      }
   }
   vector < pair < pii ,int > > pq ; 
   for(auto p : star)
   {
      int len = calco(p) ; 
      if(len>0)
      {
         pq.push_back({p,len}) ; 
         int l = p.ff-len ; 
         int r = p.ff+len ; 

         cr[l][p.ss]++ ; 
         cr[r+1][p.ss]-- ; 
         
         l = p.ss-len ; 
         r = p.ss+len ; 

         cr[p.ff][l]++;
         cr[p.ff][r+1]-- ;  
      }
   }
   

   lp(i,1,n)
   {
      int j = 1 ; 
      int sum = 0 ; 
      while(j<=m)
      {
         sum+=cr[i][j] ; 
         br[i][j]+=sum ;
         j++ ; 
      }
   }

   lp(i,1,m)
   {
      int j = 1 ; 
      int sum = 0 ; 
      while(j<=n)
      {
         sum+=cr[j][i] ; 
         br[j][i]+=sum ;
         if(br[j][i]>1)
         {
            br[j][i] = 1 ; 
         }
         j++ ; 
      }
   }
   lp(i,1,n)
   {
      lp(j,1,m)
      {
         cout << " " << br[i][j] ; 
      }
      cout << endl ; 
   }


   int f = 1 ; 
   lp(i,1,n)
   {
      lp(j,1,m)
      {
         if(ar[i][j]!=br[i][j]){f=0;}
      }
   }
   if(f==0){cout << "-1" << endl ; return 0 ; }
   cout << pq.size() << endl ; 
   for(auto x : pq )
   {
      pii p = x.ff ; 
      cout << p.ff << " " << p.ss << " " << x.ss << endl ;
   }
   return 0 ;
}