#include <stdio.h>
#include "bubblesort.c"
#include "quicksort.c"
#include "selectionsort.c"

void bubblesort();
void quicksort();
void selectionsort();

int original[7] = {12,33,1,4,6,12,9};
int a[7] = {12,33,1,4,6,12,9};

int main() {
    int i;
    bubblesort();
    printf("Bubble Sort Results: ");
    for(i=0;i<7;i++){
        printf("%i ",a[i]);
        a[i] = original[i];
    }
    printf("\n");

    quicksort(a,7);
    printf("Quick Sort Results: ");
    for(i=0;i<7;i++){
        printf("%i ",a[i]);
        a[i] = original[i];
    }
    printf("\n");

    selectionsort();
    printf("Selection Sort Results: ");
    for(i=0;i<7;i++){
        printf("%i ",a[i]);
        a[i] = original[i];
    }
    printf("\n");
}