#include<stdio.h>

int partition(int arr[], int start, int end){
    int pivot = arr[end]; // Choosing the last element as pivot
    int i = start - 1; // Index of smaller element
    int j;
    for(j = start; j < end; j++){
        if(arr[j] < pivot){
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = pivot; // Place the pivot in the correct position
    arr[end] = temp;

    return i; // Return the index of the pivot
}

void quick_sort(int arr[], int start, int end) {

    if(start < end){
        int pivot_index = partition(arr, start, end);
        quick_sort(arr, start, pivot_index - 1); // Left half
        quick_sort(arr, pivot_index + 1, end); // Right half
    }
    
}

int main(){
    int arr[] = {5, 2, 6, 4, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, n - 1);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}