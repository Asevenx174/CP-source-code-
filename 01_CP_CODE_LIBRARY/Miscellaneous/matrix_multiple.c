#include<stdio.h>
void main()
{
    int a[2][2],b[2][2],result[2][2],r,c,m,sum=0;
    for(r=0; r<2; r++)
    {
        for(c=0; c<2; c++)
        {
            scanf("%d",&a[r][c]);

        }
    }
    for(r=0; r<2; r++)
    {
        for(c=0; c<2; c++)
        {
            scanf("%d",&b[r][c]);
        }
    }
    for(r=0; r<2; r++)
    {
        for(c=0; c<2; c++)
        {

            for(m=0; m<2; m++)
            {
                sum=sum+a[r][m]*b[m][c];
            }
            result[r][c]=sum;
            sum=0;
        }
    }
    for(r=0; r<2; r++)
    {
        for(c=0; c<2; c++)
        {
            printf("%d\t",result[r][c]);
        }
        printf("\n");
    }
}
