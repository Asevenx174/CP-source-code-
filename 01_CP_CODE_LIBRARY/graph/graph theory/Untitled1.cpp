#include<iostream>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<string.h>
#include<queue>
#include<stdio.h>
#define pii pair<int,int>
#define uu first
#define vv second
#define mem(arr,n) memset(arr,n,sizeof(arr));
#include<set>
using namespace std ;
int main()
{
  int t=1;
  while(1)
  {
      int edge,f=0; vector < int > n1[10010]; set <int > sett;
      cin >> edge; if(edge==0){return 0;}
      while(edge--)
      {
          int x,y;
          cin >> x >> y ; n1[x].push_back(y) ; n1[y].push_back(x) ;
          sett.insert(x); sett.insert(y); if(x==y){f=1;}
      }
      int x,y,z;
      while(scanf("%d %d",&x,&y)==2)
      {
          int temp=0;
          if(x==0 && y==0){break;}
          else
          {
              map < int,int > level;
              map < int,int > :: iterator it ;
              level[x]=0;
              queue < int > q;
              q.push(x);
              while(!q.empty())
              {
                  int top=q.front();int siz=n1[top].size();q.pop();
                  for(int i=0;i<siz;i++)
                  {
                      int p = n1[top][i];
                      if(!level.count(p)){level[p]=level[top]+1;q.push(p);}
                  }
              }
              z =  sett.size() - level.size();
              for(it=level.begin();it!=level.end();it++)
              {
                  int w = it->vv;
                  if(w>y){temp++;}
              }
              if((y==0 && f==0 )|| n1[x].size()==0){temp=sett.size();z=0;}
          }
           cout << "Case " << t++ << ": " << temp+z << " nodes not reachable from node " << x << " with TTL = " << y << "." <<endl;
      }
  }
  return 0;
}
