#include<stdio.h>

int main()
{
    int num,i;
    float avg1,avg2,sum1 = 0,sum2 = 0;
    printf("enter number of process\n");
    scanf("%d",&num);
    int w[num],bt[num],tt[num];
    w[0] = 0;

    for(i = 0;i< num;i++)
    {
        printf("enter burst time of process %d\n",i+1);
        scanf("%d",&bt[i]);
    }

    printf("waiting time of process 1 is %d\n",w[0]);
    for(i = 1;i< num;i++)
    {
        w[i] = w[i-1] + bt[i-1];
        printf("waiting time of process %d is %d\n",i+1,w[i]);
        sum1 = sum1 + w[i];
    }

    for(i = 0;i<num;i++)
    {
        tt[i] = w[i] + bt[i];
        printf("turnaround time of process %d is %d\n",i+1,tt[i]);
        sum2 = sum2 + tt[i];
    }

    avg1 = sum1/num;
    avg2 = sum2/num;
    printf("average waiting time is %f\n",avg1);
    printf("average turnaround time is %f",avg2);
    return 0;



}