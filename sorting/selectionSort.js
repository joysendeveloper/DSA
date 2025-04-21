// A - Z
const selectionSort = (arr) => {
  let n = arr.length;
  let temp;
  let count = 0;
  for (let i = 0; i < n - 1; i++) {
    for (let j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
      count++;
    }
  }
  console.log("Count : ", count);
  return arr;
};

arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
console.log(selectionSort(arr));
