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
const ll maxx = 1e7+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ans=0,add=0 ;
map < int ,int > pq ; 
set < int > s ; 
void primeFactors(int n)
{
    int temp = 0 ; 
    int co = 0 ; 
    int c=2;
    while(n>1)
    {
        temp = 0 ; 
        if(n%c==0)
        {
           while(n>1 && n%c==0)
           { 
            temp++ ; 
            //pq[c]++ ;  
            co++ ; 
            n/=c;
           }
        }
        else 
        { 
          s.insert(c) ; 
          pq[c]+=temp ;
          c++ ; 
          co = 0 ; 
          temp = 0 ; 
        }
    }
    s.insert(c) ; 
    pq[c]+=temp ;
}
void solve()
{
   s.clear() ; 
   pq.clear() ; 
   add = 0 ; 
   ans = 0 ; 
   int n ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ; 
      primeFactors(x) ; 
   }
   for(auto i : s)
   {
      int x = pq[i] ; 
      ans+=(x/2) ; 
      add+=(x%2) ; 
   }
   ans+=(add/3) ; 
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