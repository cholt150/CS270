#include <stdio.h>
// #include "bubblesort.c"
// #include "quicksort.c"
// #include "selectionsort.c"

void sort(int *a, int n);
// void quicksort(int *a, int len);
// void selectionsort(int *a, int n);

int original[7] = {12,33,1,4,6,12,9};
int a[7] = {12,33,1,4,6,12,9};

int main() {
    int i;
    sort(a,7);
    printf("Sort Results: ");
    for(i=0;i<7;i++){
        printf("%i ",a[i]);
        a[i] = original[i];
    }
    printf("\n");

    // quicksort(a,7);
    // printf("Quick Sort Results: ");
    // for(i=0;i<7;i++){
    //     printf("%i ",a[i]);
    //     a[i] = original[i];
    // }
    // printf("\n");

    // selectionsort(a,7);
    // printf("Selection Sort Results: ");
    // for(i=0;i<7;i++){
    //     printf("%i ",a[i]);
    //     a[i] = original[i];
    // }
    // printf("\n");
}