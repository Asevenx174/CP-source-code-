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
const ll maxx = 1e6+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int n,m,a[maxx],b[maxx],c[maxx],d[maxx] ;
bool com(const pii &a,const pii &b)
{
   if(a.ff==b.ff)
   {
      return a.ss < b.ss ; 
   }
   else
   {
      return a.ff < b.ff ; 
   }
}
int main()
{
   debugMode();
   std::vector < pii > v,q ;
   int n,m ;
   cin >> n >> m ;

   for (int i = 0; i < n ; ++i)
   {
      cin >> a[i+1] ;  
   }
   for (int i = 0; i < n ; ++i)
   {
      cin >> b[i+1] ; 
      q.push_back({a[i+1],b[i+1]}) ; 
   }
   for (int i = 0; i < m ; ++i)
   {
      cin >> c[i+1] ; 
   }
   for (int i = 0; i < m ; ++i)
   {
      cin >> d[i+1] ; 
      v.push_back({c[i+1],d[i+1]}) ; 
   }

   sort(q.begin(),q.end(),com) ; 
   sort(v.begin(),v.end(),com) ;

   auto it = q.begin() ; 
   auto lt = v.begin() ; 
   int ans = 1 ; 
   while(it!=q.end())
   {
      pii temp = *it ; 
      int aa = temp.ff ; 
      int bb = temp.ss ; 
      int f = 0 ; 
     // cout << aa << " ?? " << bb << endl ;
      while(lt!=v.end())
      {
          pii temp = *lt ; 
          int cc = temp.ff ; 
          int dd = temp.ss ; 
          lt++;
          //cout << cc << " " << dd << endl ;
          if(aa<=cc && bb<=dd){f=1;break;}
      }
      it++ ; 
      if(f==0){ans=0;break;}
   }
   if(ans)
   {
      cout << "Yes" << endl ;
   }
   else
   {
      cout << "No" << endl ;
   }
   return 0 ;
}