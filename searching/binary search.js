const binarySearch = (arr, x) => {
  let n = arr.length;
  let low = 0,
    mid = parseInt(n / 2),
    high = n - 1,
    count = 0;

  arr = arr.sort((a, b) => a - b);

  console.log(arr);

  while (low < high) {
    count++;
    console.log("HIGH : ", high);
    console.log("MID : ", mid);
    console.log("LOW : ", low);
    console.log();

    if (arr[mid] == x) {
      console.log("Result : ", arr[mid]);
      console.log("Result Count: ", count);
      return x;
    }

    if (x < arr[mid]) {
      high = mid - 1;
    } else if (x > arr[mid]) {
      low = mid + 1;
    }

    mid = parseInt((low + high) / 2);
  }

  return -1;
};

arr = [11, 2, 3, 5, 4, 6, 7, 8, 9, 10, 1, 23, 24];
console.log("Answer : ", binarySearch(arr, 53));
