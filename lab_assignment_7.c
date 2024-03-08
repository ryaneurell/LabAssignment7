#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp, swaps = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps++;
            }
        }
    }
    printf("total swaps: %d\n", swaps);
}

void selectionSort(int arr[], int n) {
    int i, j, min_index, temp, swaps = 0;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
                swaps++;
            }
        }
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
    printf("total swaps: %d\n", swaps);
}

#include <stdio.h>

void countSwaps(int arr[], int n) {
    int i, j, temp, swaps;
    int swapped[n]; 

    for (i = 0; i < n; i++) {
        swapped[i] = 0;
    }

    for (i = 0; i < n; i++) {
        swaps = 0;
        if (!swapped[i]) {
            for (j = i + 1; j < n; j++) {
                if (arr[j] < arr[i]) {
                    swaps++;
                }
            }
            swapped[i] = 1;
            for (j = i + 1; j < n; j++) {
                if (arr[j] == arr[i]) {
                    swapped[j] = 1;
                }
            }
            printf("%d: %d swaps\n", arr[i], swaps);
        }
    }
}


int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    printf("array1:\n");
    countSwaps(array1, n1);
    bubbleSort(array1, n1);

    printf("\narray2:\n");
    countSwaps(array2, n2);
    selectionSort(array2, n2);

    return 0;
}
