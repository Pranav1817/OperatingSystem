#include<stdio.h>

struct process{
    int priority;
    int burst_t;
    int p_id;
};

int main()
{
    int i,j,num,temp1,temp2,temp3;
    float avg1,avg2,sum1 = 0,sum2 = 0;
    printf("enter number of process\n");
    scanf("%d",&num);
    struct process p[num];
    int wt = 0,tt[num];
    for(i = 0;i < num;i++)
    {
        p[i].p_id = i+1;
        printf("enter burst time and priority of process %d\n",i+1);
        scanf("%d%d",&p[i].burst_t,&p[i].priority);
    }

    for(i = 0;i < num;i++)
    {
        for(j = i+1;j< num;j++)
        {
            if(p[i].priority > p[j].priority)
            {
                temp1 = p[i].priority;
                p[i].priority = p[j].priority;
                p[j].priority = temp1;

                temp2 = p[i].burst_t;
                p[i].burst_t = p[j].burst_t;
                p[j].burst_t = temp2;

                temp3 = p[i].p_id;
                p[i].p_id = p[j].p_id;
                p[j].p_id = temp3;
            }
        }
    }

    for(i = 0;i < num;i++)
    {
        printf("%d\n",p[i].burst_t);
    }
    for(i = 0;i < num;i++)
    {
        printf("%d\n",p[i].p_id);
    }

    printf("Process Id    Waiting time    Turnaround time\n");
    for(i = 0;i < num;i++)
    {
        printf("%d            %d                   %d\n",p[i].p_id,wt,wt + p[i].burst_t);
        sum1 = wt + sum1;
        sum2 = wt + p[i].burst_t + sum2;
        wt += p[i].burst_t;
        
    }

    avg1 = sum1/num;
    avg2 = sum2/num;
    printf("average waiting time is %f\n",avg1);
    printf("average turnaround time is %f",avg2);
    return 0;


}