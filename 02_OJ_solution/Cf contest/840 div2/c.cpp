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

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 27,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int po[maxx+10] ; 
std::vector < int > val{0,0,
1,
1,
5,
1,
21,
1,
85,
73,
341,
89,
1365,
1,
5461,
4681,
21845,
1,
87381,
1,
349525,
299593,
1398101,
178481,
5592405,
1082401,
22369621};
void precom()
{
   int ans = 1 ; 
   for (int i = 0; i <=  maxx ; ++i)
   {
      po[i] = ans ;
      ans = ans*2 ; 
   }
}
int gen(int x)
{
  int add = 1 ;
  int ans = 0 ; 
  for(int i=1;i<=x;i++)
  {
     if(i%2==1){ans+=add;}
     add = add*2 ; 
  }
  return ans ; 
}
int calco(int x)
{
   int last = 0 ; 
   for(int i=1;i<=maxx;i++)
   {
      if(po[i]-1==x)
      {
         if(i%2==0){return gen(i);}
         return val[i] ;  
      }
      if(x<po[i]){last=i;break;}
   }
   return (po[last]-1) ; 
}
void solve()
{
   int q ;
   cin >> q ;
   while(q--)
   {
      int x ;
      cin >> x ;
      cout << calco(x) << endl ;
   }
}
int main()
{
   debugMode();
   precom() ; 
   ll test = 1 ; 
   // cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}