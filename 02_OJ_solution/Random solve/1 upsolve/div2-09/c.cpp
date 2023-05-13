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
void sw(int i,int j)
{
   for(int k=1;k<=n;k++)
   {
      swap(ar[k][i],ar[k][j]) ; 
   }
}
void sw2(int i,int j)
{
   for(int k=1;k<=n;k++)
   {
      swap(br[k][i],br[k][j]) ; 
   }
}
int check(int i)
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
int check2(int i)
{
   int a = 0 ; 
   int b = 0 ; 
   for(int j=1;j<=n;j++)
   {
      if(br[j][i]>br[j][i+1]){a=1;}
      else if(br[j][i]<br[j][i+1])
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
          int temp = check(i) ;
          if(temp!=1){ return false ; }
       }
       return true ; 
}
bool good2()
{
       for(int i=1;i<m;i++)
       {
          int temp = check2(i) ;
          if(temp!=1){ return false ; }
       }
       return true ; 
}
bool shift(int j)
{
   int f = 1 ; 
   for(int i=1;i<=n;i++)
   {
      if(ar[i][j]>ar[i][j-1])
      {
         f = 0 ; 
      }
   }
   return f ; 
}
bool shift2(int j)
{
   int f = 1 ; 
   for(int i=1;i<=n;i++)
   {
      if(br[i][j]>br[i][j-1])
      {
         f = 0 ; 
      }
   }
   return f ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
       cin >> n >> m ; 
       ar.clear() ; 
       ar.resize(n+10, vector<int>(m+10));
       br.clear() ; 
       br.resize(n+10, vector<int>(m+10));
       for(int i=1;i<=n;i++)
       {
         for(int j=1;j<=m;j++)
         {
            cin >> ar[i][j] ; 
            br[i][j] = ar[i][j] ; 
         }
       }
       set < int > s ; 
       int f = 1,idx=0 ; 
       for(int i=1;i<m;i++)
       {
          int temp = check(i) ;
          if(temp==-1){f=0;}
          if(temp==0)
          {
             s.insert(i) ;
             s.insert(i+1) ;  
          }
          if(s.size()>4){break;}
       }
       idx = s.size() ; 
       if(f==0 || idx>4)
       {
          cout << "-1" << endl ; continue ; 
       }
       auto it = s.begin() ; 
       for(int i=1;i<=idx;i++)
       {
          cr[i] = *it ; 
          it++ ; 
       }
       int l=1,r=1 ; 
       //cout << idx << endl ;
       if(idx>0)
       {
          l = cr[1] ;
          r = cr[idx] ; 
       }
       sw(l,r) ; 
       f = 0 ; 
       if(!good() && idx==4)
       {
          sw(l,r); 
          int i = 1 ;
          while(i<3)
          {
             int j = 3 ; 
             while(j<5)
             {
                sw(i,j) ; 
                if(good()){f=1;}
                j++ ; 
                sw(i,j) ; 
             }
             i++ ; 
          }
       }
       else if(good())
       {
          f = 1 ; 
       }
       //cout << idx << endl ;
       if(idx==2)
       {
          //cout << l << " " << r << endl ;
          int a = l ; 
          int b = r ; 
          sw(l,r);  
          int add = 0 ; 
          for(int i=r;i<=m;i++)
          {
             if(shift(i))
             {
                sw(i-1,i) ; 
                add++ ; 
             } 
             else{break;}
          }
          if(good())
          {
            f = 1 ; 
            r = l+add ; 
          }
          else
          {
             l = a ; 
             r = b ; 
             add = 0 ; 
             for(int i=r;i>1;i--)
             {
                 if(shift2(i))
                 {
                  sw2(i-1,i) ; 
                  add++ ; 
                 } 
                 else{break;}
             }
             l = r-add ; 
             if(good2())
             {
                f = 1 ; 
             } 
          }
       }
       if(f==0 || idx>4)
       {
          cout << "-1" << endl ; continue ; 
       }
       cout << l << " " << r << endl ;
   }
   return 0 ;
}