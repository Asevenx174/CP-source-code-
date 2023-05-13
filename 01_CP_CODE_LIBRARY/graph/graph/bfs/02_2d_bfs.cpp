
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_set>
#include<vector>
#include<queue>
#include<utility>
#include<cstring>
#define pb(a)             push_back(a)
#define mp(a,b)           make_pair(a,b)
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define loop(i,a)          for(int i=1;i<=a;i++)
#define pii                pair <int,int>
#define sl(a)              scanf("%I64d",&a)
#define sll(a,b)           scanf("%I64d %I64d",&a,&b)
#define si(a)              scanf("%d",&a)
#define sii(a,b)           scanf("%d %d",&a,&b)
using namespace std ;
typedef long long ll ;
const int maxx = 205;
string s[15];
int alpha;
map < char , pii > point ;
int fx[10]={1,-1,0,0},fy[10]={0,0,1,-1},qqq;
int bfs(pii a,pii b,char last)
{
   queue < pii > q ;
   q.push(a);
   map < pii,int > dis ;
   dis[a]=0;
   while(!q.empty())
   {
       pii u = q.front();
       int ux = u.ff , uy = u.ss ;
       q.pop();
       for(int i=0;i<4;i++)
       {
           int vx = ux+fx[i], vy = uy+fy[i] ;
           pii v = pii(vx,vy);
           char c = 'a';
           if(vx>=0 && vy>=0){c=s[vx][vy];}
           if(vx>=0 && vy>=0 && vx<qqq && vy<qqq && !dis.count(v) && c<=last && c!='#')
           {
               q.push(v);
               dis[v]=dis[u]+1;
               if(v==b){return dis[v];}
           }
       }
   }
   return -1;
}
int main()
{
    int test ;
    si(test) ;
    loop(t,test)
    {
        point.clear();
        alpha=0;
        si(qqq);
        loop(i,qqq)
        {
            string str ;
            cin >> str ;
            s[i-1]=str;
        }
        for(int i=0;i<qqq;i++)
        {
            for(int j=0;j<qqq;j++)
            {
                char x = s[i][j] ;
                if(x!='#' && x!='.'){ point[x]= mp(i,j); alpha++ ; }
            }
        }
        int ans=0 ;
        char b = 'A',a ;
        for(int i=1;i<alpha;i++)
        {
            a = b ;
            b++;
            //cout << a << " " << b << endl;
            int  part = bfs(point[a],point[b],b);
            if(part==-1){ans=-1;break;}
            ans+=part;
        }
        if(alpha==1){ans=0;}
        if (ans==-1)
        {
            pf("Case %d: Impossible\n",t);
        }
        else{pf("Case %d: %d\n",t,ans);}
    }
    return  0 ;
}
