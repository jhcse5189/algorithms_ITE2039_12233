#include <stdio.h>
#include <stdlib.h>

void heap_sort(int* a, int n);
void build_heap(int* a, int n);
void max_heapify(int* a, int idx, int n);

int left_child(int idx);
int right_child(int idx);


int main() {

  int d, i;
  int* arr;

  for ( i = 0; scanf("%d", &d); ++i ) {
    if (d == -1) {
      break;
    } else {
      arr[i] = d;
    }
  }

  int n = i;
  heap_sort(arr, n);

  for ( i = n-1; i >= 0; --i )
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}


void heap_sort(int* a, int n) {

  build_heap(a, n);
  int tmp;
  for (int i = n; i >= 2; --i) {
    tmp = a[1];
    a[1] = a[i];
    a[i] = tmp;
    max_heapify(a, 1, i - 1);
  }
}


void build_heap(int* a, int n) {

  int idx = n / 2;
  for ( idx; idx > 0; --idx)
    max_heapify(a, idx, n);
}


void max_heapify(int* a, int idx, int n) {

  int l = left_child(idx);
  int r = right_child(idx);

  int largest = idx;
  if (l <= n && a[idx] < a[l])
    largest = l;
  if (r <= n && a[largest] < a[r])
    largest = r;

  if (largest != idx) {
    int tmp = a[largest];
    a[largest] = a[idx];
    a[idx] = tmp;
    max_heapify(a, largest, n);
  }
}

int left_child(int idx) { return 2 * idx; }
int right_child(int idx) { return 2 * idx + 1; }
