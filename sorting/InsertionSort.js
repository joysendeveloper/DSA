const insertionSort = arr => {
    let count = 0;
    let n = arr.length;
    let current;
    for(let i = 1; i < n; i++){
        let j = i - 1
        current = arr[i];
        while(j >= 0 && current < arr[j]){
            count++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
    console.log('Count : ', count);
    console.log(arr);
}

arr = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1];
// arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ];
insertionSort(arr);



//Complete within 20 minutes 