#include<stdio.h>

int main()
{
    int n,m,i,j,x = 0,flag = 0,y = 0;
    printf("enter number of process and resources resp. \n");
    scanf("%d%d",&n,&m);
    int alloc[n][m], max[n][m],avail[m],need[n][m], finish[n],work[m];

    for(i = 0;i< n;i++)
    {
        printf("enter allocated resources for process %d\n",i+1);
        for(j = 0;j< m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }

    for(i = 0;i< n;i++)
    {
        printf("enter maximum resources for process %d\n",i+1);
        for(j = 0;j< m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

    printf("enter available resources\n");
    for(i = 0;i< m;i++)
    {
        scanf("%d",&avail[i]);
        work[i] = avail[i];
    }

    for(i = 0;i<n ;i++)
    {
        finish[i] = 0;
    }

    for(i = 0;i< n;i++)
    {       
        for(j = 0;j< m;j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("allocate resource\n");
    for(i = 0;i< n;i++)
    {      
        for(j = 0;j< m;j++)
        {
            printf("%d\t",alloc[i][j]);
        }
        printf("\n");
    }
    printf("max resource\n");
    for(i = 0;i< n;i++)
    {      
        for(j = 0;j< m;j++)
        {
            printf("%d\t",max[i][j]);
        }
        printf("\n");
    }
    printf("the need for process is \n");
    for(i = 0;i< n;i++)
    {      
        for(j = 0;j< m;j++)
        {
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }

    while(x < n && y < n)
    {
        for(i = 0;i< n;i++)
        {
            for(j = 0;j< m;j++)
            {
                if(need[i][j] <= work[j] && finish[i] == 0)
                {
                    flag = 1;
                    work[j] = alloc[i][j] + work[j];
                    printf("work is %d\t",work[j]);        
                }
                else{
                    flag = 0;
                    break;
                }
            }

            if(flag == 1)
            {
                finish[i] = 1;
                x++;
            }
            printf(" x is %d\n",x);

            if(flag == 0)
            {
                y++;
            }
            
        }
        
    }

    if(y > n)
    {
        printf("System is in unsafe state\n");
    }

    printf("Work is\n");
    for(i = 0;i< m;i++)
    {
        printf("%d\t",work[i]);
    }
    
}