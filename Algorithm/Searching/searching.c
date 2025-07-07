#include<stdio.h>

int linear_search(int arr[], int size, int key){
    for(int i = 0; i < size; i++){
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int binary_search(int arr[], int size, int key){
    int l = 0,
        h = size - 1,
        m;
    
    while(l <= h){
        m = (l + h) / 2;
        if(arr[m] == key)
            return m;
        else if(arr[m] < key)
            l = m + 1;
        else
            h = m - 1;
    }

    return -1;
}

int main(){
    int array[] = {2, 3, 4, 10, 40};
    int size = sizeof(array) / sizeof(array[0]);
    int key = 10;
    // int result = linear_search(array, size, key);
    int result = binary_search(array, size, key); // Uncomment to use binary search
    if(result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array\n");
    return 0;
}