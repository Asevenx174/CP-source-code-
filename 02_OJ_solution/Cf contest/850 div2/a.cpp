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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
void solve()
{
   int n ;
   cin >> n ;
   n-- ; 
   int a = 1 ; 
   int b = 0 ; 
   std::vector < int > ar,br ;
   int idx=2,co=0,pos=1 ; 
   ar.push_back(1) ; 
   while(idx<=n)
   {
      if(pos)
      {
         b+=idx ; 
         br.push_back(idx) ; 
      }
      else
      {
         a+=idx ; 
         ar.push_back(idx) ;
      }
      n-=idx ; 
      co++ ; 
      idx++ ;
      if(co==2)
      {
         pos = !pos ; 
         co = 0 ; 
      } 
   }
   if(pos){br.push_back(n);}else{ar.push_back(n);}
   int aw=0,ab=0 ; 
   int bw=0,bb=0 ;
   for(auto x : ar)
   {
      int y = x/2 ; 
      ab+=y ;
      aw+=(x-y) ; 
   }
   for(auto x : br)
   {
      int y = x/2 ; 
      bw+=y ;
      bb+=(x-y) ; 
   }
   cout << aw << " " << ab << " " << bw << " " << bb << endl ;
}
int main()
{
   debugMode();
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}