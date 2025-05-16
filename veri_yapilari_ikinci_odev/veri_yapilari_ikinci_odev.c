
#include <stdio.h>

void specialSort(int arr[], int size) {
    int i, j, temp;

    // Basit bubble sort ile sıralıyoruz
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Özel sıralama sonucu:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {60, 80, 3, 9, 57, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    specialSort(arr, size);
    return 0;
}
