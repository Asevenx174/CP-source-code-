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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int sr[maxx],tr[maxx] ; 
int main()
{
   debugMode();
   map < int,int > ci ; 
   char cc = 'a' ; 
   int idx = 1 ; 
   while(cc<='z')
   { 
      ci[cc++]=idx++ ; 
   }
   int n ;
   cin >> n ; 
   string s,t ;
   cin >> s >> t ; 
   idx = 1 ; 
   for(auto c : s )
   {
      sr[idx++]=ci[c] ; 
   }
   idx = 1 ; 
   for(auto c : t )
   {
      tr[idx++]=ci[c] ; 
   }
   sort(s.begin(),s.end()) ; 
   sort(t.begin(),t.end()) ; 
   if(s!=t)
   {
      cout << "-1" << endl ; return 0 ; 
   }
   int i = 1  ;
   std::vector< int > k ;
   while(i<=n)
   {
      if(sr[i]==tr[i]){i++;continue;}
      int j = n ; 
      while(sr[j]!=tr[i]){j--;}
      while(i<j)
      {
         swap(sr[j],sr[j-1]) ;
         k.push_back(j-1) ;  
         j-- ;
      }
      i++ ; 
   } 
   cout << k.size() << endl ; 
   idx = 1 ;
   for(auto x : k )
   {
      if(idx>1){cout << " " ; }
      idx = 2 ; 
      cout << x ; 
   }
   cout << endl ; 

   return 0 ;
}