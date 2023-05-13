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
map < int , char > ic ; 
map < char ,int > ci ; 
ll sr[5][40] ;  
bool valid()
{
   ll p=0,q=0 ; 
   ll a=0,b=0 ;
   for(int i=1;i<=26;i++)
   {
      if(sr[1][i]>0)
      {
         a = i ; break ; 
      }
   }  
   for(int i=26;i>0;i--)
   {
      if(sr[2][i]>0 && b==0 )
      {
         b = i ; 
      }
      p+=sr[1][i] ; 
      q+=sr[2][i] ; 
   } 
   if(a<b){return true;}
   if(sr[1][a]==sr[2][a] && p==sr[1][a] && p!=q)
   {
      return true ; 
   }
   else if(sr[1][a]<sr[2][a] && sr[1][a]==p )
   {
      return true ; 
   }
   return false ; 
}
int main()
{
   debugMode();
   ll idx = 1 ; 
   char ch = 'a' ; 
   while(ch<='z')
   {
      ci[ch] = idx ; 
      ic[idx] = ch ; 
      ch++ ; 
      idx++ ; 
   }
   int test ;
   cin >> test ;
   while(test--)
   {
      for(int i=1;i<=30;i++)
      {
         sr[1][i] = 0 ; 
         sr[2][i] = 0 ; 
      }
      sr[1][1] = 1 ; 
      sr[2][1] = 1 ;  
      ll q ;
      cin >> q ;
      while(q--)
      {
         ll d,k ; 
         string x ; 
         cin >> d >> k >> x ; 
         std::vector < ll > f(30,0) ;
         for(auto c : x )
         {
            f[ ci[c] ]++ ; 
         }
         for(int i=1;i<=26;i++)
         {
            sr[d][i]+=(k*f[i]) ; 
         }
         if(valid())
         {
            cout << "YES" << endl ;
         }
         else
         {
            cout << "NO" << endl ;
         }
      }
   }
   return 0 ;
}