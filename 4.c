#include <stdio.h>
#include <stdlib.h>

void bubbleSort(double array[], int size)
{
    int i;
    int j;
    int swapped;
    double temp;
    for (i = 0; i<size-1; i++) {
        swapped = 0;
        for (j = 0; j<size-1-i; j++) {
            if (array[j]>array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

int main(void)
{
    int size;
    double *array;
    int i;
    printf("Enter size of array: ");
    scanf("%d", &size);
    array = (double *)malloc(size * sizeof(double));
    if (array == NULL) {
        printf("Failed to allocate memory!\n");
        return 1;
    }
    for (i = 0; i<size; i++) {
        printf("Enter array element: ");
        scanf("%lf", &array[i]);
    }
    bubbleSort(array, size);
    printf("Sorted array: ");
    for (i = 0; i<size; i++) {
        printf("%g ", array[i]);
    }
    free(array);
    return 0;
}
