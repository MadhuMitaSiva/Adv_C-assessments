/* 
1.
Create 3 threads
threadA-> sum of first n prime number
threadB-> print every 2 sec for 100 sec
threadC-> print every 3 sec for 100 sec

2. a)
signal Handling
SIGINT 

b) time of the individual executive vs pthread execution
*/
#include<stdio.h>
#include<unistd.h>
#include<stdbool.h>
#include<stdlib.h>
#include<pthread.h>
#include<signal.h>

bool isPrime(int num)
{
    //int sq_num= sqrt(num);
    for(int i=2;(i*i)<=num;i++)
    {
        if(num%i==0)
        {
            return false;
        }
    }
    return true;
}

void *primeSum(void *num)
{
    int *n=(int *)num;
    int count=*n;
    int *sum=malloc(sizeof(int));
    *sum=0;
    int i=2; //initializing the 1st prime number
    while(count>0)
    {
        if(isPrime)
        {
            *sum=((*sum)+i);
            count--;
        }
    i++;
    }
    return (void*)sum;
}

void *delay_2sec(void* arg)
{
    for(int i=0;i<50;i++)
    {
        printf("Thread1 is running.\n");
        sleep(2);
    }
    return NULL;    
}

void *delay_3sec(void* arg)
{
    for (int j=0;j<33;j++)
    {
        printf("Thread2 is running.\n");
        sleep(3);
    }
    return NULL;
}
void sig_handler(int sig)
{
    printf("\nInterrupt Signal Caught!\n");
}

int main()
{
    signal(SIGINT,sig_handler);
    int val=5;
    void *retsum;
    pthread_t threadA;
    pthread_t threadB;
    pthread_t threadC;
    pthread_create(&threadA,NULL,primeSum,&val);
    pthread_join(threadA,&retsum);
    printf("%d\n",*(int *)retsum);
    pthread_create(&threadB,NULL,delay_2sec,NULL);
    pthread_create(&threadC,NULL,delay_3sec,NULL);
    pthread_join(threadB,NULL);
    pthread_join(threadC,NULL);
    return 0;

}
