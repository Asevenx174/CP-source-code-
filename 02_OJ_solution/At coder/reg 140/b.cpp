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
int l[maxx+10],r[maxx+10] ; 
std::vector< pii > pq ;
bool valid(int op)
{
   int d = op/2 ; 
   if(d>pq.size()){return false ;}
   int lim = pq.size()-d+1 ; 
   int sum = 0 ; 
   auto it = pq.begin() ; 
   int last = 0 ; 
   while(lim--)
   {
      pii p = *it ; 
      sum+=p.ff ; 
      last = p.ff ; 
      it++ ; 
   }
   if(op%2==1)
   {
      sum-=last ; 
   }
   else
   {
      sum-- ; 
   }
   int need = op-d ; 
   if(sum>=need){return true ;}
   return false ; 
}
int main()
{
   debugMode();
   std::vector< int > pos ;
   int n,idx=1 ;
   string s ; 
   cin >> n >> s ; 
   char p = '$' ; 
   int sum = 1;  
   for(auto c : s )
   {
      if(c=='R' && p=='A')
      {
         l[idx]=sum ; 
      }
      if(p==c)
      {
        sum++ ; 
      }
      else
      {
        sum = 1 ; 
      }
      p = c ; 
      idx++ ; 
   }

   reverse(s.begin(),s.end()) ; 
   p = '$' ; 
   sum = 1 ;  
   idx = n ; 
   for(auto c : s )
   {
      if(c=='R' && p=='C')
      {
         r[idx]=sum ; 
      }
      if(p==c)
      {
        sum++ ; 
      }
      else
      {
        sum = 1 ; 
      }
      p = c ; 
      idx-- ; 
   }
   sum = 0 ; 
   lp(i,1,n)
   {
      int len = min(l[i],r[i]) ; 
      if(len>0){pq.push_back({len,i});} 
   }
   if(pq.size()==0)
   {
      cout << "0" << endl ; return 0 ; 
   }
   sort(pq.begin(),pq.end(),greater<pii>()) ; 
   int l=0,r=mod,ans=0; 
   while(l<=r)
   {
      int mid = (l+r)/2 ;
      if(valid(mid))
      {
          ans = mid ; 
          l = mid+1 ; 
      }
      else
      {
          r = mid-1 ; 
      }
   }
   cout << ans << endl ;
   return 0 ;
}