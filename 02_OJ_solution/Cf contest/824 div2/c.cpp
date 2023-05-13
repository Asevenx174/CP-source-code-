#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10] ; 
int main()
{
   debugMode();
   map < char ,int > ci ; 
   map < int ,char > ic ; 
   int idx = 1 ;
   char ch = 'a' ; 
   while(idx<=26)
   {
      ci[ch] = idx ; 
      ic[idx] = ch ; 
      ch++ ; 
      idx++ ; 
   }
   int test ;
   cin >> test ;
   while(test--)
   {
      std::vector < int > par(maxx+10,0),ass(maxx+10,0) ;
      int n ;
      cin >> n ;
      string s ;
      cin >> s ; 
      idx = 1 ; 
      for(auto c : s )
      {
         ar[idx++] = ci[c] ; 
      }
      priority_queue < int , vector < int > , greater < int > > pq ;
      for(int i=1;i<=26;i++)
      {
         pq.push(i) ; 
      } 
      idx = 1 ; 
      while(idx<=n)
      {
         int x = ar[idx] ; 
         if(par[x]!=0){continue;}
         vector < int > temp ; 
         while(!pq.empty())
         {
           int p = pq.top() ; 
          // cout << idx << " " << p << endl ;
           if(p!=x && par[ass[x]]!=p )
           {
            cout << p << " " << x << endl ;
             ass[p] = x ; 
             par[x] = p ; 
             pq.pop() ; 
             break ; 
           }
           else
           {
              temp.push_back(p) ;
              pq.pop() ; 
           }
         }
         for(auto x : temp )
         {
            pq.push(x) ; 
         }
         idx++ ; 
      }
      for(int i=1;i<=n;i++)
      {
         int temp = par[ ar[i] ] ; 
         char c = ic[temp] ; 
         cout << c ; 
      }  
      cout << endl ;
   }
   return 0 ;
}