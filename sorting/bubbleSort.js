
const bubbleSort = (arr) => {
  let n = arr.length;
  let count = 0,
    temp;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n - i - 1; j++) {
      count++;
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  console.log("Count : ", count);
  return arr;
};

// arr = [8, 2, 4, 1, 3, 5, 7];
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
console.log(bubbleSort(arr));

