#include <stdio.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;

    '''''''''''''''''''                                                                                                                                            /
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= high && arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < j)
            swap(&arr[i], &arr[j]);
        else
            break;
    }

    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {   // FIXED
        scanf("%d", &arr[i]);   // FIXED
    }

    clock_t start, end;

    start = clock();
    quickSort(arr, 0, n - 1);   // FIXED (case-sensitive)
    end = clock();

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {   // FIXED
        printf("%d ", arr[i]);
    }

    double time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC; // FIXED
    printf("\nTime taken: %f seconds\n", time_taken); // FIXED

    return 0;
}

