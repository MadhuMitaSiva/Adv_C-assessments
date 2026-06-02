/*
Define a calender with dayName and 3tasks per day
display all by date
*/

#include<stdio.h>

struct Calender{
    char dayName[10];
    char task[3][15];
};
int main()
{
    struct Calender day[7];
    for (int i=0;i<7;i++)
    {
        printf("Enter the day:\t");
        scanf("%s",day[i].dayName);
        for (int num=0;num<3;num++)
        {
            printf("\nEnter Task %d:\t",num+1);
            scanf("%s",day[i].task[num]);
        }
    }
    for(int j=0;j<7;j++)
    {
        printf("\nDay:%s\n",day[j].dayName);
        int tasknum=0;
        while(tasknum<3)
        {
            printf("Task %d: %s\n",(tasknum+1),day[j].task[tasknum]);
            tasknum++;
        }
    }
    return 0;
}