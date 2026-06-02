/*
traverse a nxn 2d matrix that is row-wise and column-wise increasing order to find the key
*/

#include<stdio.h>
#include<stdbool.h>
int main()
{
    int key=22;
    int array[4][4]={
        {1,4,7,12},
        {2,5,8,15},
        {3,6,9,18},
        {10,19,22,25}};
    bool flag;
    int row=0;
    int col=3;
    while(row<4 && col>=0)
    {
        if(array[row][col]==key)
        {
            printf("%d Key found.\n",key);
            printf("At [row:col]=[%d:%d]\n",row,col);
            flag=true;
            break;
        }
        else if(array[row][col]>key)
        {
            col--;
        }
        else if(array[row][col]<key)
        {
            row++;
        }
    }
    if(!flag)
    {
        printf("%d Key not found in the array\n",key);
    }

    return 0;

}