#include<bits/stdc++.h>
using namespace std ;
const int maxx = 1e5+5;
vector < bool > col(2*maxx,false),d1(2*maxx,false),d2(2*maxx,false);
vector< int > column(maxx);
void nqueen(int n,int row)
{
    if(row>n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(column[i]==j){cout << " (*) ";}
                else{cout << " 0 ";}
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(col[i]==true || d1[i+row]==true || d2[n+row-i]==true){continue;}
        column[row]=i;

        col[i]=true;
        d1[i+row]=true;
        d2[n+row-i]=true;

        nqueen(n,row+1);

        col[i]=false;
        d1[i+row]=false;
        d2[n+row-i]=false;
    }
}
int main()
{
    int n ;
    cin >> n ;
    nqueen(n,1);
    return 0;
}
