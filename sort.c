#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define RANDGE_NUM 100

void FastSort(int * array, int *size, int start, int end)
{
    if(start >= end)
    {
        return;
    }

    int left = start;
    int right = end;
    int temp = array[left];

    while(left < right)
    {
        while(left < right && array[right] > temp)
        {
            right--;
        }
        if(left < right)
        {
            array[left] = array[right];
            left++;
        }
        while(left < right && array[left] < temp)
        {
            left++;
        }
        if(left < right)
        {
            array[right] = array[left];
            right--;
        }
    }
    array[left] = temp;
    FastSort(array, (int*)size,start, left - 1);
    FastSort(array, (int*)size,right + 1, end);
}

int main()
{
    int size;
    printf("Please input a size: \n");
    scanf("%d",&size);

    int *array = (int *)malloc(sizeof(int) * size);

    srand(time(NULL));
    for(int idx = 0; idx < size; idx++)
    {
        array[idx] = rand() % RANDGE_NUM + 1;
        printf("%d ",array[idx]);
    }
    printf("\n");
    FastSort(array,&size,0,size - 1);
    for(int idx = 0; idx < size; idx++)
    {
        printf("%d ",array[idx]);
    }
    printf("\n");
    return 0;
}