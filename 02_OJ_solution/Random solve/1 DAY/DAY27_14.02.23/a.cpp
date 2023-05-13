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
const ll maxx = 100+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n,p ; 
void solve()
{
  cin >> n >> p  ;
  map < int ,int > pq ; 
  for (int i = 0; i < n ; ++i)
  {
     int x ;
     cin >> x ;
     ar[i+1] = x ; 
     pq[x] = 1 ;  
  }
  int val = 0 ; 
  for (int i = n-1 ; i>=0 ; --i)
  {
     int x = ar[i+1] ; 
     if(x!=p-1){val=x;break;}
  }
  int x = ar[n] ; 
  int l,r ; 
  int idx = p-1 ; 
  while(idx>x && pq[idx]==1){idx--;}
  int ans = 0 ; 
  if(pq[idx]==0 && idx>x)
  {
     r = idx ; 
     ans = r-x ; 
  }
  if(ar[n]==p-1)
  {
     if(ans==0 && (pq[val+1]==0 || pq[0]==0) ){ans=1;}
     pq[val+1] = 1 ; 
     pq[0] = 1 ; 
  }
  idx = x-1 ; 
  while(pq[idx]==1 && idx>=0){idx--;}
  if(pq[idx]==0 && idx>=0)
  {
     //cout << idx << endl ; 
     l = idx ;
     ans = (p-1-x)+(l+1) ;
  }
  cout << ans << endl ;
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