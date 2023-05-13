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
int n,m,cr[maxx+10]; 
std::vector < vector < int > > ar,br ;
int check2(int i)
{
   int a = 0 ; 
   int b = 0 ; 
   for(int j=1;j<=n;j++)
   {
      if(ar[j][i]>ar[j][i+1]){a=1;}
      else if(ar[j][i]<ar[j][i+1])
      {
         b = 1 ; 
      }
   }
   if(a==1 && b==1){return -1;}
   if(a==1){return 0;}
   return 1 ; 
}
bool good()
{
       for(int i=1;i<m;i++)
       {
          int temp = check2(i) ;
          if(temp!=1){ return false ; }
       }
       return true ; 
}
void sw(int i,int j)
{
   for(int k=1;k<=n;k++)
   {
      swap(ar[k][i],ar[k][j]) ; 
   }
}
std::vector< int > col ;
bool check(int i)
{
   std::vector < int > k ;
   for(int j=1;j<=m;j++)
   {
      k.push_back(ar[i][j]);
   }
   sort(k.begin(),k.end()) ; 
   int idx = 1 ; 
   bool ans = true ; 
   for(auto x : k )
   {
      if(x!=ar[i][idx])
      {
         col.push_back(idx) ; 
         ans = false; 
      }
      idx++ ;
   }
   return ans ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
       col.clear() ; 
       cin >> n >> m ; 
       ar.clear() ; 
       ar.resize(n+10, vector<int>(m+10));
       for(int i=1;i<=n;i++)
       {
         for(int j=1;j<=m;j++)
         {
            cin >> ar[i][j] ; 
         }
       }
       if(good()){ cout << "1 1" << endl ; continue ; }
       int l=1,r=1 ; 
       for(int i=1;i<=n;i++)
       {
          if(!check(i))
          {
             if(col.size()>2){break;}
             sw(col[0],col[1]);
             l = col[0] ; 
             r = col[1] ; 
             break ;
          }
       }
       if(good())
       {
          cout << l << " " << r << endl ; 
       }
       else
       {
          cout << "-1" << endl ;
       }
   }
   return 0 ;
}