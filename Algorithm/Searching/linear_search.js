function linear_search(arr, x) {
  let n = arr.length;
  for (let i = 0; i < n; i++) {
    if (arr[i] == x) return "Found : " + x;
  }
  return "Not Found " + -1;
}

arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
console.log(linear_search(arr, 10));
