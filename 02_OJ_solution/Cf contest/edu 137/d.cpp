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
int main()
{
   debugMode();
   int n ;
   cin >> n ;
   string s ;
   cin >> s ;
   int i = 0 ; 
   std::vector < int > v[5] ;
   int f = 0 ; 
   int op = 0,temp=0 ; 
   while(i<n)
   {
      char ch = s[i] ; 
      int x = s[i]=='0' ? 0 : 1 ; 
      int j = i ; 
      while(i+1<n && s[i+1]==ch)
      {
         i++ ; 
      }
      int len = i-j+1 ;
      if(f==0 && x==1)
      {
         temp = len ; 
      }
      if(x==1){f=1;}
      if(f){v[x].push_back(len);op++;} 
      i++ ;  
   }
   op = op/2 ; 
   int a = mod ; 
   int b = 0 ; 
   int best = 0 ; 
   for(int i=0;i<op;i++)
   {
      a = min(v[1][i],a) ; 
      b = max(v[0][i],b) ;  
      best = max(best,min(a,b)) ; 
   }
   int idx = 1 ; 
   reverse(s.begin(),s.end()) ; 
   f = 0 ; 
   for(auto c : s )
   {
      if(c=='0')
      {
         f = idx ; 
      }
      idx++ ; 
   }
   //cout << temp << " " << f << endl ;
   if(temp>=f)
   {
      for (int i = 0; i < n ; ++i)
      {
         cout << "1" ; 
      }
      cout << endl ; return 0 ; 
   }
   reverse(s.begin(),s.end()) ; 
   vector < char > st ; 
   idx = 0 ; 
   int co = 0 ; 
   for(auto c : s )
   {
      if(c=='1')
      {
         co = 1 ; 
         st.push_back(c) ;  idx++ ; continue ; 
      }
      char ch = '0' ; 
      if(idx-best>=0)
      {
         if(s[idx-best]=='1')
         {
            ch = '1' ; 
            co = 1 ; 
         }
      }
      st.push_back(ch) ;
      idx++ ; 
   }
   if(co==0)
   {
      cout << "0" << endl ; return  0 ; 
   }
   for(auto c : st )
   {
      cout << c  ;
   }
   cout << endl ;
   return 0 ;
}