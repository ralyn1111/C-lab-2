
#include <stdio.h>
#include <stdlib.h>

void shifted(double array[], int shift, int size)
{
    int moved;
    int start;
    int now;
    int next;
    double temp;
    double saved;
    shift = (shift%size+size)%size;
    moved = 0;
    for (start = 0; moved<size; start++) {
        now = start;
        temp = array[now];
        do {
            next = (now+shift) % size;
            saved = array[next];
            array[next] = temp;
            temp = saved;
            now = next;
            moved++;
        } while (now != start);
    }
}

int main(void)
{
    int size;
    int shift;
    double *array;
    int i;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter shift: ");
    scanf("%d", &shift);
    array = (double *)malloc(size * sizeof(double));
    if (array == NULL) {
        printf("Failed to allocate memory!\n");
        return 1;
    }
    i = 0;
    for (; i < size; i++) {
        printf("Enter array element: ");
        scanf("%lf", &array[i]);
    }
    shifted(array, shift, size);
    printf("Shifted array: ");
    i = 0;
    for (; i < size; i++) {
        printf("%g ", array[i]);
    }
    free(array);
    return 0;
}
