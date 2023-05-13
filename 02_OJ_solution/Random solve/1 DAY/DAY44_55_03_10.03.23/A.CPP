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
ll ar[maxx+10],br[maxx+10],n ; 
void sett(string s,int pos)
{
   map < char ,int > pq ; 
   for(auto c : s)
   {
      pq[c]++ ; 
   }
   char ch = 'a' ; 
   int idx=0,add1=0,add2=0 ; 
   while(ch<='z')
   {
      int temp = 1 << idx ; 
      int f = pq[ch] ; 
      if(f!=0){add1+=temp;}
      if(f%2==1){add2+=temp;}
      ch++ ; 
      idx++ ;
   }
   ar[pos] = add1 ; 
   br[pos] = add2 ; 
   //cout << pos << " " << ar[pos] << " " << br[pos] << endl ;
}
int calco(int x)
{
   int co = 0 ; 
   int idx = 0 ; 
   while(1)
   {
      int temp = 1 << idx ; 
      if(temp>x){break;}
      if( (temp&x)!=0 ){co++;}
      idx++ ; 
   }
   return co ; 
}
void solve()
{
   int n ;
   cin >> n ;
   map < int ,int > pq ; 
   for (int i = 0; i < n ; ++i)
   {
      string s ;
      cin >> s ; 
      sett(s,i) ; 
      //pq[br[i]]++ ; 
     /// cout << br[i] << endl ;
   }
   int m = (1 << 25) ; 
   m-- ; 
   //cout << calco(m) << endl ; return ;
   ll ans = 0  ; 
   for (int i = 0; i < n ; ++i)
   {
      for (int j = i+1 ; j < n ; ++j)
      {
         int val = br[i]^br[j] ;
         if(val==m)
         {
            cout << i << " " << j << endl ;
         }  
      }
   }
   for (int j = 0; j < n ; ++j)
   {
      int b = br[j] ; 
      int y = m^b ;
      ll add = pq[y] ;
      ans+=add  ;  
      cout << calco( (b^y) ) << endl ; 
      pq[b]++ ; 
   }
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