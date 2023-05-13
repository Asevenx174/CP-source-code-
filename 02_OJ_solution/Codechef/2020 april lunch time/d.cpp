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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],p,q,n ; 
int main()
{
   debugMode();
   cin >> n >> p >> q ;
   std::vector < int > br ;
   br.push_back(0) ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ;
      if(ar[i+1]>p || ar[i+1]<q){br.push_back(i+1);} 
   }
   br.push_back(n+1) ; 
   for(int i=1;i<br.size();i++)
   {
      int l = br[i-1]+1 ; 
      int r =  br[i]-1 ; 
      queue < int > ps ,qs ; 
      int lastp = l-1 ; 
      int lastq = l-1 ; 
      while(l<=r)
      {
         if(ar[l]==p)
         {
            ps.push(l) ; 
         }
         else if(ar[l]==q)
         {
            qs.push(l) ;
         }
         if(ps.empty() || qs.empty()){l++;continue;}
         int a,b ; 
         if(ps.size()==1)
         {
            a = qs.front()+1 ; 
            b = l-1 ;  
            while(!qs.empty()){qs.pop();}
            lastp = ps.front() ; 
         }
         else
         {
            a = ps.front()+1 ; 
            b = l-1 ;  
            while(!ps.empty()){ps.pop();}
            lastq = qs.front() ; 
         }
         cout << a << " " << b << endl ;
         l++;
      }
   }
   return 0 ;
} 