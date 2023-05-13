#include<bits/stdc++.h>
/*#define pb           push_back
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
///  ios::sync_with_stdio(0); cin.tie(0); */

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e6+10,mod=35,imax=2e9+10,qq=1,zz=0;



map < int , char > ic ; 
map < char ,int > ci ; 

string s,t ; 
int sr[maxx+10],n ; 
std::vector < int > g[mod] ;
bool valid(int idx)
{
   int p = 0 ; 
   while(idx<=n)
   {
      int x = sr[idx] ; 
      auto it = upper_bound(g[x].begin(),g[x].end(),p) ;
      if(it==g[x].end()){return false;}
      p = *it ;  
      idx+=2 ; 
   }
   return true ; 
}
int main()
{
  // debugMode();
   char ch = 'a' ; 
   int idx = 1 ; 
   while(ch<='z')
   {
      ic[idx] = ch ; 
      ci[ch] = idx ; 
      ch++ ; 
      idx++ ; 
   }



   cin >> s >> t ; 
   n = s.size() ; 
   idx = 1 ; 
   for(auto c : s )
   {
      sr[idx++] = ci[c] ;  
   }
   idx = 1 ; 
   for(auto c : t )
   {
      int x = ci[c] ; 
      g[x].push_back(idx) ; 
      idx++ ; 
   }
   int f = 0 ; 
   if(valid(1)){f=1;}
   if(n>1)
   {
      if(valid(2))
      {
         f = 1 ; 
      }
   }
   if(f)
   {
      cout << "Yes" << endl ;
   }
   else
   {
      cout << "No" << endl ;
   }
   return 0 ;
}