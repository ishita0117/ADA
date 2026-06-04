#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int temp[100000];

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[100000], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);



    printf("\nGenerated elements:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
        printf("%d ", arr[i]);
    }

    clock_t start, end;
    double time_taken;

    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();

    time_taken = ((double)(end - start)) *1000.0/ CLOCKS_PER_SEC;

    printf("\n\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\nTime taken: %f seconds\n", time_taken);

    return 0;
}

