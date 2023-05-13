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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int id[maxx+10],ar[maxx+10] ;
bool used[maxx+10] ;  
void solve()
{ 
   memset(used,false,sizeof(used)) ; 
   int n,flag=0 ;
   cin >> n ; 
   std::vector < int > v ; 
   for (int i = 0; i < n ; ++i)
   {
      int j = i+1 ; 
      int x ;
      cin >> x ; 
      ar[j] = x ; 
      id[x] = j ; 
      if(j>1 && ar[j]==j-1 && ar[j-1]==j && !used[j] && flag==0)
      {
         used[j-1] = true ; 
         used[j] = true ; 
         flag = j ; 
      }
      v.push_back(x) ; 
   }
   int ans = 0 ; 
   for(auto x : v)
   {
      int i = id[x] ; 
      if(i==x || used[i]){continue;}
      int j = x ; 
      int y = ar[j] ;
      // ar[i]=x ... ar[j] = y 
      swap(ar[i],ar[j]) ; 
      swap(id[x],id[y]) ; 
      ans++ ; 
   }
   //cout << ans << endl ;
   if(ans==0)
   {
      if(flag==0)
      {
         ans = 1 ; 
      }
      else
      {
         ans = 0 ; 
      }
      cout << ans << endl ;
   }
   else
   {
      if(flag==0)
      {
         ans++ ; 
      }
      else
      {
         ans-=2 ; 
      }
      cout << ans << " " << flag << endl ;
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