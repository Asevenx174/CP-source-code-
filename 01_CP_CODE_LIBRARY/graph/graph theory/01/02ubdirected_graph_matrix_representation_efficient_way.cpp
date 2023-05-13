#include<bits\stdc++.h>
using namespace std ;
int main()
{
    int Node,Edge;
    int matrix[100][100];
    scanf("%d%d",&Node,&Edge);
    for(i=0; i<Edge; i++)
    { ///n1 theke n2 te jete cost poriman khoroch hoy
        int n1,n2,cost;
        scanf("%d%d%d",&n1,&n2,&cost);
        matrix[n1][n2]=cost;
        matrix[n2][n1]=cost;
    }
    return 0;
}
