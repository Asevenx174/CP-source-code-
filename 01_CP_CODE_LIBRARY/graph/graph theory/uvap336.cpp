#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string.h>
#include<queue>
#include<stdio.h>
#define pii pair<int,int>
#define uu first
#define vv second
#define mem(arr,n) memset(arr,n,sizeof(arr));
using namespace std ;
int main()
{
   int edge ;
   while(1)
   {   scanf("%s",&edge);if(edge==0){return 0;}
       vector < int  > n1[50];
       while(edge--)
       {
           int x,y;
           cin >> x >> y ;
           n1[x].push_back(y);
           n1[y].push_back(x);
       }
       int x,y;
       while(scanf("%d %d",&x,&y)==2 && (x!=0 && y!=0))
       {
          int v[1000],temp=0;
          mem(v,-1);
          queue < int > q ;
          q.push(x);
          v[x]=0;
          while(!q.empty())
          {
              int top = q.front();q.pop();
              int siz = n1[top].size();
              for(int i=0;i<siz;i++)
              {
                  int p = n1[top][i];
                  if(v[p]==-1){v[p]=0;q.push(p);temp++;}
              }
              y--;
              if(y==0){break;}
          }
          cout << temp << endl;
       }
   }
}
