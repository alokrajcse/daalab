#include <stdio.h>
int n=6;
int p[]={30,35,15,5,10,20,25};
int s[6][6];
int m[6][6]={0};
void p_o_p(int s[][6],int i,int j)
{
    if(i==j)
    {
          printf("A%d",i);
    }
    else
    {
          printf("(");
          p_o_p(s,i,s[i][j]);
          p_o_p(s,s[i][j]+1,j);
          printf(")");
    }
}
int main() {
    int j,min,q;
    for(int d=1;d<=n-1;d++)
    {
        for(int i=1;i<=n-d;i++)
        {
            j=i+d;
            min=99999;
            for(int k=i;k<j;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<min)
                {
                    min=q;
                    s[i][j]=k;
                }
            }
                m[i][j]=min;
            }
        }
        printf("m matrix\n");
        for(int i=1;i<=6;i++)
        {
            for(int j=1;j<=6;j++)
            {
                printf("%d\t",m[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        printf("s matrix\n");
        for(int i=1;i<=6;i++)
        {
            for(int j=1;j<=6;j++)
            {
                printf("%d\t",s[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        p_o_p(s,1,5);
        return 0;
}