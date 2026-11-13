#include <stdio.h>
#include <stdlib.h>

void separate(int array[], int size)
{
    int position;
    int i;
    int j;
    int temp;
    position = 0;
    for (i=0; i<size; i++) {
        if (array[i]<0) {
            temp = array[i];
            for (j = i; j>position; j--) {
                array[j] = array[j-1];
            }
            array[position] = temp;
            position++;
        }
    }
    for (i = position; i<size; i++) {
        if (array[i] == 0) {
            for (j = i; j>position; j--) {
                array[j] = array[j-1];
            }
            array[position] = 0;
            position++;
        }
    }
}

int main(void)
{
    int size;
    int *array;
    int i;
    printf("Enter size of array: ");
    scanf("%d", &size);
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Failed to allocate memory!\n");
        return 1;
    }
    for (i = 0; i<size; i++) {
        printf("Enter array element: ");
        scanf("%d", &array[i]);
    }
    separate(array, size);
    printf("Rearranged array: ");
    for (i = 0; i<size; i++) {
        printf("%d ", array[i]);
    }
    free(array);
    return 0;
}
