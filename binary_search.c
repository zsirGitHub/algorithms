#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX_LEN 100

/**
 * return the index of key.
 * return -1 when failed.
 */
int binary_search(int *array, int imin, int imax, int key)
{
    int imid;

    if(array == NULL || imin > imax) {
        return -1; 
    }

    while(imin <= imax) {
        imid = imin + (imax - imin) / 2;  //avoid integer overflow
        if(array[imid] == key) {
            return imid;
        } else if(array[imid] > key) {
            imax = imid - 1; 
        } else {
            imin = imid + 1;
        }
    }

    return -1;
}

int main(int argc, char *argv[])
{
    int array[ARRAY_MAX_LEN], array_len;
    int key;
    int i;
    char input_char;

    while(1) {
        array_len = rand()%ARRAY_MAX_LEN;
        printf("length of array is %d \r\n", array_len);
        for(i = 0; i < array_len; i++) {
            array[i] = i;
        }

        key = rand()%ARRAY_MAX_LEN;
        printf("finding %d from array...\r\n", key);
        i = binary_search(array, 0, array_len-1, key);
        if(i >= 0) {
            printf("[success] array[%d] = %d\r\n", i, array[i]);
        } else {
            printf("[fialed] can not find %d!\r\n", key);
        }
        
        printf("please input 'q' to exit or other key to continue.\r\n");
        scanf("%c", &input_char);
        if(input_char == 'q') {
            break;
        }

        scanf("%c", &input_char);/*receive the 'enter' key from input*/
    }

    return 0; 
}
