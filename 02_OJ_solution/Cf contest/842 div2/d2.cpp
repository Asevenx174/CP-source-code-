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
int pr[maxx+10],id[maxx+10],n ; 
bool used[maxx+10] ; 
int calco()
{
   int add = 0  ;
      for(int i=1;i<=n;i++)
      {
         if(pr[i]==i || used[i]){continue;}
         int x = pr[i] ; 
         int j = x ; 
         int y = id[x] ; 
         // ar[i]=x ... ar[j] = y 
         swap(pr[i],pr[j]) ; 
         swap(id[x],id[y]) ; 
         cout << i << " " << j << endl ;
         add++ ; 
      }
   return add ; 
}
void ch(int i,int j)
{
   swap(pr[i],pr[j]) ; 
   swap(id[i],id[j]) ;  
}
void solve()
{
   int so=1,ad=0 ;
   cin >> n ; 
   for(int i=1;i<=n;i++)
   {
      int x ;
      cin >> x ;
      pr[i] = x ; 
      id[x] = i ; 
      if(x!=i){so=0;}
   }
   if(so){cout << "1" << endl ;return;}
   int idx = 0,f=0 ; 
   for(int i=2;i<=n;i++)
   {
      if(pr[i]==i-1 && pr[i-1]==i)
      {
         used[i] = true ; 
         used[i-1] = true ;
         f = 1 ; break ; 
      }
      else if(pr[i]==i-1)
      {
         idx = i ; 
      }
      else if(pr[i-1]==i)
      {
         idx = i-1 ;
      }
   }
   int ans = 0 ; 
   if(f)
   {
      ans = calco() ; 
      cout << ans << endl ;
   }
   else if(idx!=0)
   {
      if(pr[idx]==idx+1)
      {
         ch(idx+1,id[idx]) ;
         ans++ ;  
      }
      else
      {
         ch(idx-1,id[idx+1]) ; 
         ans++ ; 
      }
      ans+=calco() ; 
      cout << ans << endl ;
   }
   else
   {
      ans = 1+calco() ; 
      cout << ans << endl ;
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