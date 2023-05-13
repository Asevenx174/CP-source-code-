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
ll ar[maxx+10],n ; 
std::vector < ll > prime ;
void get()
{
   for(ll i=2;i<=50;i++)
   {
      ll j=2,f=1 ; 
      while(j<i)
      {
         if(i%j==zz){f=0;}
         j++ ; 
      }
      if(f){prime.push_back(i);}
   }
}
bool valid(ll p)
{
   vector < ll > pq(p+5,0) ;  
   for (int i = 0; i < n ; ++i)
   {
      ll x = ar[i+1]%p ; 
      pq[x]++ ; 
   }
   for (int i = 0; i < p ; ++i)
   {
      if(pq[i]<tt){return false ;}
   }
   return true ;
}
void solve()
{
   set < ll > s ; 
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ;
      s.insert(ar[i+1]) ;  
   }
   if(s.size()!=n)
   {
      cout << "NO" << endl ; return ;
   }
   for(auto x : prime)
   {
      if(valid(x))
      {
         cout << "NO" << endl ;
         return ; 
      }
   }
   cout << "YES" << endl ;
}
int main()
{
   debugMode();
   get() ; 
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}