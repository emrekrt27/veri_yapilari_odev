#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500

void insertionSort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int size) {
    int i, j, min_idx, temp;
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void copyArray(int src[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

int main() {
    int original[SIZE], arr1[SIZE], arr2[SIZE];
    srand(42);
    for (int i = 0; i < SIZE; i++) {
        original[i] = rand() % 1001;
    }
    copyArray(original, arr1, SIZE);
    copyArray(original, arr2, SIZE);

    clock_t start, end;
    double time_taken;

    start = clock();
    insertionSort(arr1, SIZE);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort süresi: %.6f saniye\n", time_taken);

    start = clock();
    selectionSort(arr2, SIZE);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort süresi: %.6f saniye\n", time_taken);

    return 0;
