#include<stdio.h>

void merge_sort(int arr[], int start, int end){
    for (int i = start; i <= end; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    if(start >= end) return;
    int mid = start + (end - start) / 2;
    printf("start: %d, end: %d, mid: %d\n", start, end, mid);

    merge_sort(arr, start, mid); // Left half
    merge_sort(arr, mid + 1, end); // Right half

    merge(arr, start, mid, end); // Merge the two halves

}

void merge(int arr[], int start, int mid, int end){
    int i = start,
        j = mid + 1,
        k = 0;
    int temp[end - start + 1];
    
    // Compare and merge the two halves
    while (i <= mid && j <= end){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    
    // Merge the remaining part of left halves 
    while (i <= mid)
        temp[k++] = arr[i++];

    // Merge the remaining part of right halves
    while (j <= end)
        temp[k++] = arr[j++];
        
    // Copy the merged elements back to the original array
    for(int i = 0; i < k; i++)
        arr[start + i] = temp[i];
}


int main(){
    int arr[] = {12, 31, 35, 8, 32, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, n -1);

    printf("Merged Array : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    printf("\n");

    return 0;
}