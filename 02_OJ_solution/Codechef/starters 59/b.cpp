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
const ll maxx = 1010 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n ; 
int main()
{
   debugMode();
   int test ; 
   cin >> test ;
   while(test--)
   {
      deque < int > dq ; 
      cin >> n ;
      string s ;
      cin >> s ;
      int idx = 1 ;
      for(auto c : s )
      {
         int x = c=='1' ? 1 : 0 ; 
         ar[idx++] = x ; 
      }
      int l=1,r=n ;
      idx = 1 ;  
      while(l<=r)
      {
         if(l==r)
         {
            if(idx%2==1)
            {
               if(ar[l]==1)
               {
                 dq.push_back(1) ; 
               }
               else
               {
                 dq.push_front(0) ;
               }
            }
            else
            { 
               if(ar[l]==1)
               {
                 dq.push_front(1) ; 
               }
               else
               {
                 dq.push_back(0) ;
               }
            }
            break ; 
         }
         if(idx%2==1)
         {
            // a 
            if(ar[l]==1 && ar[r]==1)
            {
               if(ar[l+1]==1)
               {
                  dq.push_back(1) ; 
                  l++ ; 
               }
               else
               {
                  dq.push_back(1) ;
                  r-- ; 
               }
            }
            else if(ar[l]==0 && ar[r]==0)
            {
               if(ar[l+1]==0)
               {
                  dq.push_front(0) ;
                  r--  ; 
               }
               else
               {
                  dq.push_front(0) ;
                  l++ ; 
               }
            }
            else if(ar[l]==1)
            {
                dq.push_front(0) ;
                r-- ; 
            }
            else
            {
                dq.push_front(0) ;
                l++ ; 
            }
         }
         else
         {
            if(ar[l]==1 && ar[r]==1)
            {
               if(ar[l+1]==1)
               {
                  dq.push_front(1) ; 
                  r-- ; 
               }
               else
               {
                  dq.push_front(1) ;
                  l++ ; 
               }
            }
            else if(ar[l]==0 && ar[r]==0)
            {
               if(ar[l+1]==0)
               {
                  dq.push_back(0) ;
                  l++  ; 
               }
               else
               {
                  dq.push_back(0) ;
                  r-- ; 
               }
            }
            else if(ar[l]==1)
            {
                dq.push_front(1) ;
                l++ ; 
            }
            else
            {
                dq.push_front(1) ;
                r-- ; 
            }
         }
         idx++ ; 
      }
      idx = 0 ; 
      while(!dq.empty())
      {
         cout << dq.front() ; 
         dq.pop_front() ; 
      }
      cout << endl ;
   }
   return 0 ;
}