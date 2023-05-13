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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}

int nxt[maxx+10],n,q,ar[maxx+10] ; 
void  precompute_spf()
{
    int root = sqrt(maxx) ; 
    for (int i = 2; i < maxx; ++i) 
    {
        if (nxt[i] == 0)
        {
            nxt[i] = i;
            if (i > root ) continue ;
            for (int j = i * i; j < maxx ; j += i)
            {
                if (nxt[j] == 0) nxt[j] = i;
            }
        }
    }
}
ll g = 1 ;
map < int ,int > fr[maxx+10] ;
multiset < int > s[maxx+10] ;   
void calco(int idx,int x)
{
   while(x>1)
   {
      ll p=nxt[x],co=0 ; 
      //cout << x << " " << p << endl ;
      while(nxt[x]==p)
      {
         co++ ; 
         x = x/nxt[x] ; 
      }
      //map < int ,int > pq = fr[idx][] ; 
      int pev = 0 ;
      if(s[p].size()==n)
      {
        pev = (*s[p].begin()) ;
      } 
      int f = fr[idx][p] ; 
      if(f>0)
      {
         s[p].erase(s[p].find(f)) ; 
      } 
      fr[idx][p]+=co ;  
      s[p].insert(f+co) ; 
      if(s[p].size()==n)
      {
         auto it = s[p].begin() ; 
         int l = *it ; 
         while(pev<l)
         {
            g = (g*p)%mod ; 
            pev++ ; 
         }
      }
   }
}
int main()
{
   debugMode() ; 
   precompute_spf() ;  
   cin >> n >> q ; 
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ; 
      calco(i+1,x) ; 
   }
   for (int i = 0; i < q ; ++i)
   {
       int idx,x ;
       cin >> idx >> x ; 
       calco(idx,x) ; 
       cout << g << endl ; 
   }
   return 0 ;
}