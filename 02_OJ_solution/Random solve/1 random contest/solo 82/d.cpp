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
int ar[maxx+10],n,ans=0 ;
bool dp[maxx+10][5][maxx+5] ;  
void calco(int idx,int last,int k)
{
   if(dp[idx][last][k])
   {
      return ; 
   }
   if(idx>n)
   {
      if(last==0){ans++;}
      return ; 
   }
   if( abs(k- (ar[idx]-1)) < 2 || k==0 ) {  calco(idx+1, ( (ar[idx]-1)*last) %2 , ar[idx]-1 ) ; } 
   if( abs(k- (ar[idx])) < 2 || k==0 ) {  calco(idx+1, ( (ar[idx])*last) %2 , ar[idx] ) ; } 
   if( abs(k- (ar[idx]+1)) < 2 || k==0 ) {  calco(idx+1, ( (ar[idx]+1)*last) %2 , ar[idx]+1 ) ; } 
   dp[idx][last][k] = true ; 
}
void solve()
{
   memset(dp,false,sizeof(dp)) ; 
   ans = 0 ; 
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   calco(2,(ar[1]-1)%2,0) ;
   calco(2,ar[1]%2,0) ;
   calco(2,(ar[1]+1)%2,0 ) ; 
   cout << ans << endl ; 
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