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
   ll test ;
   cin >> test ;
   while(test--)
   {
      std::vector< int > s[5] ;
      int n ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         int x ;
         cin >> x ;
         s[x%2].push_back(x) ; 
      }
      sort(s[0].begin(),s[0].end()) ; 
      sort(s[1].begin(),s[1].end()) ;

      int  f = 0  ; 
      if(s[0].size()==0 || s[1].size()==0 ){cout << "YES" << endl; continue ;}

          auto it = s[1].begin() ; 
          auto lt = s[0].rbegin() ; 

          if(*lt+1<*it){f=1;}

          it = s[0].begin() ; 
          lt = s[1].rbegin() ; 
          if(*lt+1<*it){f=1;}
          cout << *lt << " " << *it << endl ;
          if(f)
          {
            cout << "YES" << endl ; 
          }
          else
          {
            cout << "NO" << endl ;
          }
   } 
   return 0 ;
}