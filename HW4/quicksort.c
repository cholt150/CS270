void sort(int *a, int n) {
    if (n < 2) return;
  
    int pivot = a[n / 2];
  
    int i, j;
    for (i = 0, j = n - 1; ; i++, j--) {
      while (a[i] < pivot) i++;
      while (a[j] > pivot) j--;
  
      if (i >= j) break;
  
      int temp = a[i];
      a[i]     = a[j];
      a[j]     = temp;
    }
  
    sort(a, i);
    sort(a + i, n - i);
}