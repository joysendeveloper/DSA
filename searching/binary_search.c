#include <stdio.h>

int binarySearch(int arr[], int n, int x) {
    int low = 0, mid, high, count = 0;

    // Sort the array (you can use any sorting algorithm)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    high = n - 1;

    while (low <= high) {
        count++;
        mid = (low + high) / 2;

        printf("HIGH : %d\n", high);
        printf("MID : %d\n", mid);
        printf("LOW : %d\n\n", low);

        if (arr[mid] == x) {
            printf("Result : %d\n", arr[mid]);
            printf("Result Count: %d\n", count);
            return x;
        }

        if (x < arr[mid]) {
            high = mid - 1;
        } else if (x > arr[mid]) {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {11, 2, 3, 5, 4, 6, 7, 8, 9, 10, 1, 23, 24};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 53;

    printf("Answer : %d\n", binarySearch(arr, n, x));

    return 0;
}
