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
ll ar[maxx+10],x,y,n ; 
ll right(ll val,ll idx)
{
  while(idx<=n && ar[idx]<=val){val++;idx++;}
  return idx ; 
}
void solve()
{
   cin >> n >> x >> y ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   sort(ar+qq,ar+n+qq) ; 
   ll idx = right(x,1) ; 
   if(idx>n)
   {
      cout << (y-x) << endl ; return ;
   }
   ll add = idx-qq ; 
   ll g = 0 ; 
   do
   {
      //cout << x << " " << idx << endl ;
      if(x+add>=y)
      {
         g+=(y-x) ; 
         cout << g << endl ; return ;
      }
      ll sub = n-add ; 
      if(sub>=add){ cout << "-1" << endl ; return ;}
      ll per = add-sub ;  
      //x+=per ; 
      //g+=n ;
      //idx = right(x+add,idx) ;
      ll l=qq,r=1e12,co=1 ; 
      while(l<=r)
      {
         ll m = (l+r)/tt ; 
         ll temp = (m*per) ;
         temp+=x ;  
         temp+=add ; 
         ll pos = right(temp,idx) ;
         if(pos==idx)
         {
            co = m ; 
            l = m+qq ;  
         }
         else
         {
            r = m-qq ; 
         }
      }
      //co = 1 ; 
      x+=(per*co) ; 
      g+=(n*co) ;
      idx = right(x+add,idx) ;
      add = idx-qq ;   
   }
   while(idx<=n) ;
   g+=(y-x) ; 
   cout << g << endl ;  
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