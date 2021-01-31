void quicksort(int *a, int len) {
    if (len < 2) return;
  
    int pivot = a[len / 2];
  
    int i, j;
    for (i = 0, j = len - 1; ; i++, j--) {
      while (a[i] < pivot) i++;
      while (a[j] > pivot) j--;
  
      if (i >= j) break;
  
      int temp = a[i];
      a[i]     = a[j];
      a[j]     = temp;
    }
  
    quicksort(a, i);
    quicksort(a + i, len - i);
}