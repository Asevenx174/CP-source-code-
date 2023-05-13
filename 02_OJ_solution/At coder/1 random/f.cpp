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
const ll maxx = 5010 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n,br[maxx+10] ; 
void calco(int j)
{
   if(j==n)
   {
      int x = ar[j-2] ; 
      int y = ar[j-1] ; 
      int z = ar[j] ; 
      ar[j]=x ; 
      ar[j-1]=z ; 
      ar[j-2]=y ;  
   }
   else
   {
      int x = ar[j-1] ; 
      int y = ar[j] ; 
      int z = ar[j+1] ;
      ar[j-1] = y ; 
      ar[j] = z ; 
      ar[j+1] = x ;  
   }
   return ; 
}

void calco2(int j)
{
   // j<
   if(j==1)
   {
      int x = ar[j] ; 
      int y = ar[j+1] ; 
      int z = ar[j+2] ; 
      ar[j] = z ; 
      ar[j+1] = x ; 
      ar[j+2] = y ; 
   }
   else
   {
      int x = ar[j-1] ; 
      int y = ar[j] ; 
      int z = ar[j+1] ; 
      ar[j-1] = z ; 
      ar[j] = x ; 
      ar[j+1] = y ; 
   }
   return ; 
}
int main()
{
   debugMode();
   std::vector< int > a,b ;
   cin >> n ;
   lp(i,1,n)
   {
      cin >> ar[i] ; 
      a.push_back(ar[i]) ; 
   }
   lp(i,1,n)
   {
      cin >> br[i] ; 
      b.push_back(br[i]) ;
   }
   sort(a.begin(),a.end()) ; 
   sort(b.begin(),b.end()) ; 
   int f = 1 ; 
   auto it = a.begin() ; 
   auto lt = b.begin() ; 
   while(it!=a.end())
   {
      if(*it!=*lt){f=0;}
      it++;
      lt++;
   }
   if(f==0)
   {
      cout << "No" << endl ; return 0 ; 
   }
   lp(i,1,n-2)
   {
      if(ar[i]==br[i]){continue;}
      int j=i+1 ;
      while(ar[j]!=br[i])
      {
         j++ ; 
      }
      while(i!=j)
      {
        calco(j) ; 
        j-- ; 
      }
   }
   f = 1 ; 
   int g = 1 ; 
   lp(i,1,n)
   {
      if(ar[i]!=br[i]){f=0;}
   }
   swap(ar[n],ar[n-1]) ; 
   for(int i=n-2;i>0;i--)
   {
      if(ar[i]==br[i]){continue;}
      int j = i-1 ; 
      while(ar[j]!=br[i])
      {
         j-- ; 
      }
      while(j<i)
      {
         calco2(j);
         j++;
      }
   }
   lp(i,1,n)
   {
      if(ar[i]!=br[i]){g=1;}
   }
   if(max(f,g)==1)
   {
      cout << "Yes" << endl ; 
   }
   else
   {
      cout << "No" << endl ; 
   }
   return 0 ;
}