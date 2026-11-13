#include <stdio.h>
#include <stdlib.h>

void quickSort(double array[], int left, int right)
{
    int middle;
    double pivot;
    int i;
    int j;
    double temp;
    while (left<right) {
        middle = left+(right-left)/2;
        pivot = array[middle];
        array[middle] = array[right];
        array[right] = pivot;
        i = left;
        j = right-1;
        while (i<=j) {
            while (i<=j && array[i]<pivot) {
                i++;
            }
            while (i<=j && array[j]>=pivot) {
                j--;
            }
            if (i<j) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
        }
        array[right] = array[i];
        array[i] = pivot;
        if (i-left<right-i) {
            if (left<i-1) {
                quickSort(array, left, i-1);
            }
            left = i+1;
        } else {
            if (i+1<right) {
                quickSort(array, i+1, right);
            }
            right = i-1;
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
    quickSort(array, 0, size - 1);
    printf("Sorted array: ");
    for (i = 0; i<size; i++) {
        printf("%g ", array[i]);
    }
    free(array);
    return 0;
}
