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
const ll maxx = 2000+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int n ; 
string a,b,c,d,e,sr[maxx+10] ; 
void proc(string s)
{
   a="" ; 
   b="" ;
   c="" ; 
   d="" ; 
   e="" ; 
   int len = s.size() ; 
   int idx = 0 ; 
   while(s[idx]!='#')
   {
      a+=s[idx] ; 
      idx++ ; 
   }
   idx++ ; 
   while(s[idx]!=' ')
   {
      b+=s[idx] ; 
      idx++ ; 
   }
   idx++ ; 
   while(s[idx]!=' ')
   {
      c+=s[idx] ; 
      idx++ ; 
   }
   idx++ ; 
   while(s[idx]!=' ')
   {
      d+=s[idx] ; 
      idx++ ; 
   }
   idx++ ; 
   while(idx<len)
   {
      e+=s[idx] ; 
      idx++ ; 
   }
   //cout << a << " " << b << " " << c << " " << d << " " << e << endl ;
}
int getv(string s)
{
   int x = s[0]-'0' ; 
   int y = s[1]-'0' ; 
   x = x*10  ;
   return (x+y) ; 
}
int gets()
{
   string temp = "" ;
   temp+=b[0] ; 
   temp+=b[1] ;  
   int ans = 0 ; 
  // cout << temp << endl ;
   ans+=getv(temp)*(3600);
   temp="" ; 
   temp+=b[3] ; 
   temp+=b[4] ; 
 //  cout << temp << endl ;
   ans+=getv(temp)*(60);
   temp="" ; 
   temp+=b[6] ; 
   temp+=b[7] ; 
   //cout << temp << endl ;
   ans+=getv(temp) ;
  // cout << ans << endl ; 
   return ans ; 
}
int get()
{
   int x = a[1]-'0' ; 
   x = (x*86400)+gets() ;
   return x ; 
}
int getbirth()
{
   int ans = 0,idx=1 ; 
   for (int i = 9 ; i>5 ; i-- )
   {
      int x = d[i]-'0' ; 
      x = x*idx ; 
      ans+=x ; 
      idx = idx*10 ;  
   }
   return ans ; 
}
map < string , int > bd ; 
void ini()
{
   bd["A+"] = 0 ;
   bd["A-"] = 0 ;
   bd["AB+"] = 0 ;
   bd["AB-"] = 0 ;
   bd["B+"] = 0 ;
   bd["B-"] = 0 ;
   bd["O+"] = 0 ;
   bd["O-"] = 0 ;
}
void solve()
{
   ini() ; 
   map < int ,int > byear ; 
   map < string ,int > pq ; 
   set < string > st ; 
   cin >> n ; 
   cin.ignore() ;  
   for (int i = 0; i < n ; ++i)
   {
      string x ; 
      getline(cin,x);
      sr[i+1] = x ; 
      proc(x) ; 
      //cout << x << endl ; 
      st.insert(c) ; 
   }
  //return ; 
   for(auto x : st)
   {
      pq[x] = -mod ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      string x = sr[i+1] ;
      proc(x) ; 
      int en = get() ; 
      //cout << x << " " << en <<  endl ;
      if(pq[c]<en)
      {
         pq[c] = en ; 
      } 
   }
   for (int i = 0; i < n ; ++i)
   {
      string x = sr[i+1] ;
      proc(x) ; 
      int en = get() ; 
     // cout << c << " " << en << endl ;
      if(pq[c]==en)
      {
        // cout << c << endl ;
         int temp = getbirth() ; 
         bd[e]++ ; 
         byear[temp]++ ;
         //pq[c] = mod ; 

      }
      //cout << a << " " << b << " " << c << " " << d << " " << e << endl ;
   }
  // return ; 
   for(auto x : bd)
   {
      cout << x.ff << " " << x.ss << endl ;
   }
   for(auto x : byear)
   {
      cout << x.ff << " " << x.ss << endl ;
   }
}
int main()
{
   //debugMode();

  /* a = "01/02/2023" ; 
   b = "15:58:31" ; 
   int en = get() ; 
   cout << en << endl ;
   return 0 ;*/
   ll test = 1 ; 
   // cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}