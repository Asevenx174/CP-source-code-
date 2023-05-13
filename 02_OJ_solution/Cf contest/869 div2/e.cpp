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
/// vector<vector<int>> vec( n , vector<int> (m));
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
int n,sr[maxx+10] ; 
string s ; 
std:: queue < pii > v[50] ;
int calco(int val)
{
   int temp = 0 ; 
   for(int i=1;i<=n/2;i++)
   {
      int j = n-i+1 ; 
      if(sr[i]!=val && sr[j]!=val){temp++;}
   }
   return temp ; 
}
void solve()
{
   for (int i = 0; i < 30; ++i)
   {
      while(!v[i].empty()){v[i].pop();}
   }
   cin >> n ; 
   string s ;
   cin >> s ; 
   if(n%2==1){cout << "-1" << endl ; return ;}
   for(int i=1;i<=n;i++)
   {
      int x = (s[i-1]-'a')+1 ; 
      sr[i] = x ; 
   }
   for(int i=1;i<=(n/2);i++)
   {
      int j = n-i+1 ; 
      if(sr[i]==sr[j])
      {
         v[ sr[i] ].push( {i,j} ) ; 
      }
   }
   priority_queue < pii > pq ; 
   for(int i=1;i<=26;i++)
   {
      int len = v[i].size() ; 
      if(len>0)
      {
         pq.push({len,i}) ; 
      }
   }
   int ans = 0 ; 
   while(pq.size()>1)
   {
      pii a = pq.top() ; pq.pop() ;
      pii b = pq.top() ; pq.pop() ;
      
         pii x = v[a.ss].front() ; v[a.ss].pop() ; 
         pii y = v[b.ss].front() ; v[b.ss].pop() ;
         swap(sr[x.ff],sr[y.ff]) ;  
         ans++ ;  

      if(a.ff>1){pq.push({a.ff-1,a.ss});}
      if(b.ff>1){pq.push({b.ff-1,b.ss});} 
   }
   if(pq.empty()){cout << ans << endl ; return ;}
   int f = pq.top().ff ; 
   int have = calco(pq.top().ss) ; 
   if(f>have){cout << "-1" << endl ; return ;}
   ans+=f ; 
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