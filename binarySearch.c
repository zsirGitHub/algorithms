#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX_LEN 100

int binarySearch(int *array, int size, int target)
{
    int left = 0;
    int right = size - 1;
    int mid;
    int i;

    if(array == NULL || size <= 0)
    {
        return -1; 
    }

    while(left <= right)
    {
        mid = left + (right - left) / 2;  //avoid integer overflow
        if(array[mid] == target)
        {
            return mid;
        }
        else if(array[mid] > target)
        {
            right = mid - 1; 
        }
        else
        {
            left = mid + 1;
        }
    }

    return -1;
}

int main(int argc, char *argv[])
{
    int array[ARRAY_MAX_LEN];
    int array_size;
    int target;
    int i;
    char input_char;

    while(1)
    {
        array_size = rand()%ARRAY_MAX_LEN;
        printf("array_size:%d \r\n", array_size);
        for(i = 0; i < array_size; i++)
        {
            array[i] = i;
        }

        target = rand()%100;

        printf("target:%d \r\n", target);
        i = binarySearch(array, array_size, target);
        if(i >= 0)
        {
            printf("find target: array[%d] = %d\r\n", i, array[i]);
        }
        else
        {
            printf("can not find target!\r\n");
        }
        
        scanf("%c", &input_char);
        if(input_char == 'q')
        {
            break;
        }
    }

    return 0; 
}
