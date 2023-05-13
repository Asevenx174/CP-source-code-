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
#define pii                pair < int , int >

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
ll n,k,ar[maxx+10],hr[maxx+10],pr[maxx+10] ; 
void solve()
{
   priority_queue < pii , vector < pii> , greater < pii > > pq ; 
   cin >> n >> k ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> hr[i+1] ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      cin >> pr[i+1] ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      pq.push({pr[i+1],hr[i+1]}) ; 
   }
   ll sub = 0,f=0 ; 
   while(!pq.empty())
   {
      pii t = pq.top() ; pq.pop() ; 
      ll p = t.ff ; 
      ll h = t.ss-sub ; 
      if(f==1 && h>zz)
      {
         k-=p ; f = 0 ; 
      }
      while(h>zz && k>zz)
      {
         h-=k ;
         if(h>zz)
         {
            h-=k ; 
            sub+=k ; 
            k-=p ; 
         } 
         else
         {
            sub+=k ; 
            f=1 ; 
            break ;  
         }
      }
      if(h>zz){k=-1;break;}
   }
   if(k<zz)
   {
      cout << "NO" << endl ;
   }
   else
   {
      cout << "YES" << endl ;
   }
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