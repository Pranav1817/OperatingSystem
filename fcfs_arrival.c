#include<stdio.h>

int main()
{
    int num,i,sum1 = 0,sum2 = 0;
    float avg1,avg2;
    printf("enter number of process\n");
    scanf("%d",&num);
    int wt[num],bt[num],tt[num],st[num],at[num];    //st - service time, at- arrival time
    wt[0] = 0;
    st[0] = 0;

    for(i = 0;i< num;i++)
    {
        printf("enter arrival time and burst time of process %d\n",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }

  
    printf("waiting time of process 1 is %d\n",wt[0]);
    for(i = 1;i< num;i++)
    {
        st[i] = st[i-1] + bt[i-1];
        wt[i] = st[i] - at[i];
        printf("waiting time of process %d is %d\n",i+1,wt[i]);
        sum1 = sum1 + wt[i];
    }

    for(i = 0;i<num;i++)
    {
        tt[i] = wt[i] + bt[i];
        printf("turnaround time of process %d is %d\n",i+1,tt[i]);
        sum2 = sum2 + tt[i];
    }

    avg1 = sum1/num;
    avg2 = sum2/num;
    printf("average waiting time is %f\n",avg1);
    printf("average turnaround time is %f",avg2);
    return 0;



}