#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
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
ll a,b,c,k ; 
ll ar[20],dr[20],per,have,need,flag ;
void calco(ll a)
{
      ll d = 0 ; 
      if(a>=per)
      {
         d = a-per ; 
         if(d%k!=0)
         {
            flag = 0 ;
         }
         else
         {
            have+=(d/k) ; 
         }
      }
      else
      {
         d = per-a ; 
         if(d%k!=0)
         {
            flag = 0 ;
         }
         else
         {
            need+=(d/k) ; 
         }
      }
} 
int main()
{
   //debugMode();
   ll test,co=1 ;
   cin >> test ;
   while(test--)
   {
      cin >> a >> b >> c >> k ; 
      flag = 1 ; 
      ll sum = a+b+c ;
      per = sum/3 ; 
      need = 0 ;
      have = 0 ;
      if(sum%3!=0){flag=0;}
      calco(a);
      calco(b);
      calco(c);
      if(need!=have){flag=0;}
      cout << "Case " << co++ << ": " ; 
      if(flag)
      {
         cout << "Peaceful" << endl ;
      }
      else
      {
         cout << "Fight" << endl ;
      }
   }
   return 0 ;
}