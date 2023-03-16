// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int m = len / 2;
  for (int i = 0; i < len; i++) {
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int l = i;
    int r = len - 1;
    while (r - 1 > l) {
      int m = (l + r) / 2;
      if (arr[m] + arr[i] < value) {
        l = m;
      } else if (arr[m] + arr[i] > value) {
        r = m;
      } else {
        count++;
        int mid = m - 1;
        while (mid > l && arr[mid] + arr[i] == value) {
          count++;
          mid--;
        }
        mid = m + 1;
        while (mid < r && arr[mid] + arr[i] == value) {
          count++;
          mid++;
        }
        break;
      }
    }
  }
  return count;
}
