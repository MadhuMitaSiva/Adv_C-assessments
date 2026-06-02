/*
Function takes integer array and size.
Rearrange the even and odd in-place in relative order
*/
#include<stdio.h>

void arrayRearranger(int *arr,int size)
{
    int temp[size];
    int *ptr=temp;
    for(int i=0;i<size;i++)
    {
        if(*(arr+i)%2==0)
        {
            *ptr=*(arr+i);
            ptr++;
        }
    }
    for(int i=0;i<size;i++)
    {
        if(*(arr+i)%2!=0)
        {
            *ptr=*(arr+i);
            ptr++;
        }
    }
    ptr=temp;
    for(int i;i<size;i++)
    {
        *(arr+i)=*(ptr+i);
    }
}

int main()
{
    int array[7]={1,2,5,4,6,3,8};
    int size=7;
    arrayRearranger(array,size);
    printf("Rearranged array:\n");
    for(int i=0;i<size;i++)
    {
        printf("%d\t",*(array+i));
    }
    printf("\n");
    return 0;

}