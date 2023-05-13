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

#define SL(a)              scanf("%I64d",&a)
#define SLL(a,b)           scanf("%I64d %I64d",&a,&b)
#define PL(x) printf("%I64d\n",(x))
#define PLL(x,y) printf("%I64d %I64d\n",x,y)

#define S(a)              scanf("%d",&a)
#define SS(a,b)           scanf("%d %d",&a,&b)
#define P(x) printf("%d\n",(x))
#define PP(x,y) printf("%d %d\n",x,y)

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

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
map < string , char > pq ; 
map < char ,char > cc ; 
void sett()
{
  pq["clank"]='a' ;
  pq["bong"]='b' ;
  pq["click"]='c' ;
  pq["tap"]='d' ;
  pq["poing"]='e' ;

  pq["clonk"]='f' ;
  pq["clack"]='g' ;
  pq["ping"]='h' ;
  pq["tip"]='i' ;
  pq["cloing"]='j' ;

  pq["tic"]='k' ;
  pq["cling"]='l' ;
  pq["bing"]='m' ;
  pq["pong"]='n' ;
  pq["clang"]='o' ;

  pq["pang"]='p' ;
  pq["clong"]='q' ;
  pq["tac"]='r' ;
  pq["boing"]='s' ;
  pq["boink"]='t' ;

  pq["cloink"]='u' ;
  pq["rattle"]='v' ;
  pq["clock"]='w' ;
  pq["toc"]='x' ;
  pq["clink"]='y' ;
  pq["tuc"]='z' ; 

  char ch = 'a',p='A' ;
  while(ch<='z')
  {
     cc[ch] = p ; 
     ch++ ; 
     p++ ; 
  }  
}

stack < char > ans ; 
int a = 0 ; 
int b = 0 ; 
void calco(string s,int k)
{
   char ch = pq[s] ; 
   if('a'<=ch && ch<='z')
   {
      if(k)
      {
        ch = cc[ch] ; 
      }
      ans.push(ch) ; 
   
   }
   else if(s=="whack")
   {
      ans.push(' ') ; 
   }
   else if(s=="pop")
   {
      if(ans.empty()){ans.pop();}
   }
   else if(s=="bump")
   {
      a = !a ; 
   }
   else if(s=="dink")
   {
      b = 1 ; 
   }
   else
   {
      b = 0 ; 
   }
}
int main()
{
   debugMode();
   sett() ; 
   int n ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      string s ;
      cin >> s ;
      calco(s,(a^b)) ; 
   }
   stack < char > fin ; 
   while(!ans.empty())
   {
      fin.push(ans.top()) ; 
      ans.pop() ; 
   }
   while(!fin.empty())
   {
      cout << fin.top() ; 
      fin.pop() ; 
   }
   cout << endl ;
   return 0 ;
}