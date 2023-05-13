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
const ll maxx = 105 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
} 
int f[maxx+10] ; 
int main()
{
   debugMode();
   int n ;
   cin >> n ;
   string s ;
   cin >> s ;
   set < char > st ; 
   for(auto c :s )
   {
      st.insert(c) ; 
   }
   int idx = 1 ; 
   map < char ,int > ci ; 
   map < int , char > ic ; 
   for(auto c : st )
   {
      ci[c] = idx ; 
      ic[idx] = c ; 
      idx++ ;  
   }
   idx-- ; 
   for(auto c : s )
   {
      f[ ci[c] ] ++ ; 
   }
   queue < int > q,p ; 
   for(int i=1;i<=idx;i++)
   {
      int y = f[i]/2 ; 
      int ex = f[i]%2 ; 
      //cout << i << " " << y << " " << ex << endl ;
      if(ex>0)
      {
         q.push(i) ; 
      }
      while(y--)
      {
         p.push(i) ; 
         p.push(i) ; 
      }
   }
   int k = p.size()/2 ; 
   std::vector < int > d ;
   for(int i=1;i*i<=n;i++)
   {
      if(n%i==0)
      {
         int j = n/i ; 
         d.push_back(i) ; 
         if(i==j){continue;}
         d.push_back(j) ;
      }
   }
   sort(d.begin(),d.end(),greater<int>()) ; 
   int len = 1 ; 
   for(auto l : d)
   {
      int f = n/l ;
      int need = 0 ; 
      if(l%2==0)
      {
         need = (l/2)*f ; 
      } 
      else
      {
         need = ((l-1)/2)*f ; 
      }
      if(k>=need)
      {
         len = l ; 
         break ; 
      }
   }
   int temp = n/len ; 
   idx = 0 ; 
   cout << temp << endl ;
   while(temp--)
   {
      if(idx==1){cout << " " ; }
      idx = 1 ; 
      deque < int > dq ; 
      int h = len/2 ; 
      if(len%2==1)
      {
         while(q.empty())
         {
            q.push(p.front()) ;
            p.pop() ; 
            q.push(p.front()) ;
            p.pop() ; 
         }
         dq.push_front(q.front()) ; 
         q.pop() ;  
      }
      while(h--)
      {
         dq.push_front(p.front()) ; 
         p.pop() ;
         dq.push_back(p.front()) ; 
         p.pop() ;
      }
      while(!dq.empty())
      {
         cout << ic[dq.front()]  ; 
         dq.pop_front() ; 
      }
   }
   cout << endl ;
   return 0 ;
}