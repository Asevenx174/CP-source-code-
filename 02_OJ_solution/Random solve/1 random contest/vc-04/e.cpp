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
bool calco(char a,char b,char c,char d,int pos)
{
   if(pos)
   {
      if(a==b){return true ;}else{return false;}
   }
   map < char ,int > f ;
   f[a]++ ; 
   f[b]++ ; 
   f[c]++ ; 
   f[d]++ ; 
   int l = min(min(min(f[a],f[b]),f[c]),f[d]) ;
   int r = max(max(max(f[a],f[b]),f[c]),f[d]) ;   
   set < char > s ; 
   s.insert(a) ; 
   s.insert(b) ;
   s.insert(c) ;
   s.insert(d) ;
   if(s.size()==4)
   {
      return false ; 
   }
   else if(s.size()==1)
   {
      return true ; 
   }
   else if(l==2 && r==2)
   {
      return true ; 
   }
   else if(r==3)
   {
      return false ; 
   }
   else if(r==2 && l==1)
   {
      return false ; 
   }
}
int main()
{
   debugMode();
   int n ;
   cin >> n ;
   string a,b ;
   cin >> a >> b ; 
   int ans = 0 ; 
   int lim = (n+1)/2 ; 
   int flag = (n%2)==1 ? 1 : 0 ; 
   for(int i=1;i<=lim;i++)
   {
      int l = i-1 ; 
      int r = n-i ; 
      //ans+=calco(a[l],b[l],a[r],b[r],0) ; 
      set < char > temp ; 
      temp.insert(a[l]) ;
      temp.insert(b[l]) ;
      temp.insert(a[r]) ;
      temp.insert(b[r]) ;
      int best = mod ; 
      int send = 0 ; 
      if(i==lim && flag==1)
      {
         send = 1 ; 
      }
      for(auto x : temp )
      {
         for(auto y : temp )
         {
            int add = 0 ; 
            if(x!=a[l]){add++;}
            if(y!=a[r] && l!=r){add++;}
            if(calco(x,b[l],y,b[r],send))
            {
               best = min(best,add) ; 
            }
         }
      }
      ans+=best ; 
   }
   cout << ans << endl ;
   return 0 ;
}