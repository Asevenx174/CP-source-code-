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
const ll maxx = 300+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}

/*
4 4 4 4 4
1 9 10 3
2 4 5 6
20 7 2 15
3 2 5 12 
*/
int ar[maxx+10][maxx+10],br[maxx+10][maxx+10] ;  
int rr[maxx+10][maxx+10] ;
int cc[maxx+10][maxx+10] ; 
int pr[maxx+10][maxx+10] ; 
int H,W,n,h,w ; 
int lx[maxx+10],rx[maxx+10] ; 
int ly[maxx+10],ry[maxx+10] ; 
int calco(int r1,int r2,int c1,int c2)
{
   int sub = 0 ; 
   for(int i=1;i<=maxx;i++)
   {
      if(lx[i]==mod){continue;}
      if( r1<=lx[i] && rx[i]<=r2 && c1<=ly[i] && ry[i]<=c2 )
      {
         sub++ ; 
      }
   }
   return sub ; 
}
void solve()
{
   for (int i = 0; i < maxx ; ++i)
   {
      lx[i] = mod ; 
      rx[i] = 0 ; 
      ly[i] = mod ; 
      ry[i] = 0 ; 
   }
   set < int > s ; 
   cin >> H >> W >> n >> h >> w ; 
   int dis = 0 ; 
   map < int , int > pq ; 
   for (int i = 0; i < H ; ++i)
   {
      for (int j = 0; j < W ; ++j )
      {
         ll x ;
         cin >> x ; 
         ar[i+1][j+1] = x ;  
         s.insert(x) ; 
         lx[x] = min(lx[x],i+1) ;
         rx[x] = max(rx[x],i+1) ;
         ly[x] = min(ly[x],j+1) ;
         ry[x] = max(ry[x],j+1) ;
      }
   }
   dis = s.size() ; 
   for(int k=0;k<=(H-h);k++)
   {
      for(int l=0;l<=(W-w);l++)
      {
         if(l>0){cout << " " ; }
         int r1 = k+1 ; 
         int r2 = k+h ; 
         int c1 = l+1 ; 
         int c2 = l+w ; 
         int ans = 0 ; 
         if(r1<=r2 && c1<=c2)
         {
            ans = dis-calco(r1,r2,c1,c2) ; 
            cout << ans ; 
         }
      }
      cout << endl ; 
   } 
}
int main()
{
   debugMode();
   ll test = 1 ; 
   // cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}