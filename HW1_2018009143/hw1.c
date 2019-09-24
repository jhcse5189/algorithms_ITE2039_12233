#include <stdio.h>

void heap_sort(int* a, int n);
void build_heap(int* a, int n);
void max_heapify(int* a, int idx, int n);

int left_child(int idx);
int right_child(int idx);


int main() {

  int x = 0;

  int arr_1[10];
  int buffer = 0;

  for ( ; x < 10; ++x, scanf("%d", &buffer)) {
     if (buffer == -1) break;
     else arr_1[x] = buffer;
   }

  heap_sort(arr_1, x-1);

  printf("x:%d\n", x);
  for ( int i = 1; i < x; ++i )
    printf("%d ", arr_1[i]);
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
