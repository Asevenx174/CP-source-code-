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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
map < int ,int > f ; 
string s ; 
int n,l=1,r=n,ar[maxx+10],pos ; 
queue < int > pq ;
bool check(int val)
{
    if(pq.size()<2){return false ;}
    int x = pq.front() ; pq.pop() ; 
    int y = pq.front() ; pq.pop() ; 
    if(val>max(x,y))
    {
       ar[l++] = max(x,y) ; 
       ar[r--] = min(x,y) ; 
       f[x]-- ;
       f[y]-- ;  
       pos = 1 ; 
       return true ; 
    }
    pq.push(y) ; 
    pq.push(x) ; 
    return false ; 
}
void sett(int val,int temp)
{
   if( check(val) ) { return ; }
   while(temp--)
   {
      ar[l++] = val ; 
      ar[r--] = val ; 
   }
} 
int br[maxx+10] ; 
string getstring(int idx)
{
   int a=l,b=r ; 
   for(int i=1;i<=n;i++)
   {
      if(l<=i && i<=r){continue;}
      br[i] = ar[i] ; 
   }
   f[idx]-- ; 
   br[a++] = idx ; 
   int i = 1 ;
   while(a<=b)
   {
      int temp = f[i] ; 
      while(temp--)
      {
         br[b--] = i ; 
      }
      i++ ; 
   }
   string ans = "" ; 
   for (int i = 0; i < n ; ++i)
   {
      int x = br[i+1] ; 
      char c = x+96 ; 
      ans+=c ; 
   }
   f[idx]++ ; 
   return ans ; 
}
void solve()
{
   while(!pq.empty()){pq.pop();}
   f.clear() ; 
   cin >> s ;
   n = s.size() ;  
   l = 1 ; 
   r = n ; 
   for(auto c : s)
   {
      int x = c-96 ; 
      //cout << x << endl ; 
      f[x]++ ; 
   }
   int idx=1 ; 
   pos = 0 ; 
   int flag = 0 ; 
   string ex = "zzzzzzzzzzzzzzzzzzzzzzzz" ; 
   while(idx<=26 && pos==0)
   {
       sett(idx,f[idx]/2) ; 
       if(pos){break;}
       f[idx] = f[idx]%2 ; 
       if(f[idx]==1)
       {
           if(flag==0)
           {
              ex = getstring(idx) ; 
           }
           pq.push(idx) ; 
           flag = 1;  
       }
       idx++ ; 
   }

   if(pos==0 && !pq.empty())
   {
       pos = pq.front() ; 
       ar[l++] = pos ; 
       f[pos] = 0 ;  
   }
   for(int i=1;i<=26;i++)
   {
      while(f[i]--)
      {
         ar[l++] = i ; 
      }
   }
   string ans = "" ; 
   for (int i = 0; i < n ; ++i)
   {
      int x = ar[i+1] ; 
      char c = x+96 ; 
      ans+=c ; 
   }
   string temp = ans ; 
   reverse(temp.begin(),temp.end()) ; 
   ans = max(ans,temp) ; 
   //cout << ans << " " << ex << endl ;
   if(flag)
   {
      string kk = ex ; 
      reverse(kk.begin(),kk.end()) ; 
      temp = max(kk,ex) ; 
      ans = min(ans,temp) ; 
   }
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