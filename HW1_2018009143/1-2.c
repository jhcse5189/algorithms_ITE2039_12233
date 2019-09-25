#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* heap_k_sort(int** a, int k, int n);
void build_heap(int* a, int* b, int n);
void min_heapify(int* a, int* b, int idx, int n);

int left_child(int idx);
int right_child(int idx);



int main(int argc, char* argv[]) {

  FILE* f = fopen("input1-2.txt", "r");
  int n, k, i, j;

  char* line = NULL;
  size_t line_size = 0;
  char delim[] = " ";


  fscanf(f, "%d", &n);
  fgetc(f);
  k = n;


  //dynamic allocation of array.
  int** arrs = (int**)malloc(n * sizeof(int*));
  for ( i = 0; i < n; ++i ) {
    arrs[i] = (int*)malloc(101 * sizeof(int));
  }


  //read.
  for ( i = 0, n = 0; i < k; ++i) {

    getline(&line, &line_size, f);
    char *c = strtok(line, delim);

      for ( j = 1; c != NULL && j < 101; ++j) {
        arrs[i][j] = atoi(c);
        c = strtok(NULL, delim);
      }
      arrs[i][0] = j-1;
      n += j-1;
  }
  fclose(f);

  //int* res = (int*)malloc(n * sizeof(int));
  int* res = heap_k_sort(arrs, k, n);

  printf("seg5.5:\n");
  for ( i = 0; i < n; ++i )
    printf("%d ", *(res + i));

  printf("seg6:\n");
  // //print.
  // for ( i = 0; i < k; ++i) {
  //   for ( j = 1; j < arrs[i][0]; ++j)
  //     printf("arrs[%d][%d] : %d\t", i, j, arrs[i][j]);
  //   printf("\n");
  // }
  // for ( i = 0; i < k; ++i) {
  //   free(arrs[n]);
  // }
  // free(arrs);

  for ( i = 0; i < k; ++i) {
    free(arrs[i]);
  }
  free(arrs);

  return 0;
}



int* heap_k_sort(int** a, int k, int n) {

  int res[n];
  int i, j;

  int** a_copy = (int**)malloc(k * sizeof(int*));
  for ( i = 0; i < k; ++i) {
    a_copy[i] = (int*)malloc(101 * sizeof(int));
  }

  for ( i = 0; i < k; ++i ) {
    for ( j = 0; j <= a[i][0]; ++j )
      a_copy[i][j] = a[i][j];
  }

  int k_heap[k+1];
  int k_tag[k+1];

  for ( int i = 1; i < k; ++i ) {
    k_heap[i] = a_copy[i-1][1];
    k_tag[i] = i-1;
    a_copy[i-1][0] -= 1;
  }
  build_heap(k_heap, k_tag, k);

  printf("seg3\n");

  for ( i = 0; i < n; ++i) {

    res[i] = k_heap[1];
    if (a_copy[k_tag[1]][0] == 0) {
      //replace k_heap's root with element's max value
      k_heap[1] = 1000;
      min_heapify(k_heap, k_tag, 1, k);
    } else {
      printf("tag?:%d\n", k_tag[1]);
      printf("a[][0]:%d\n", a[k_tag[1]][0]);
      printf("a_copy[][0]:%d\n", a_copy[k_tag[1]][0]);
      k_heap[1] = a_copy[k_tag[1]][a[k_tag[1]][0]-a_copy[k_tag[1]][0]+1];
      min_heapify(k_heap, k_tag, 1, k);
    }
  }

  printf("seg4\n");

  for ( i = 0; i < k; ++i) {
    free(a_copy[i]);
  }
  free(a_copy);

  printf("seg5\n");

  return res;
}


void build_heap(int* a, int* b, int n) {

  int idx = n / 2;
  for ( idx; idx > 0; --idx)
    min_heapify(a, b, idx, n);
}


void min_heapify(int* a, int* b, int idx, int n) {

  int l = left_child(idx);
  int r = right_child(idx);

  int smallest = idx;
  if (l <= n && a[idx] > a[l])
    smallest = l;
  if (r <= n && a[smallest] > a[r])
    smallest = r;

  if (smallest != idx) {
    int tmp_a = a[smallest];
    int tmp_b = b[smallest];

    a[smallest] = a[idx];
    b[smallest] = b[idx];

    a[idx] = tmp_a;
    b[idx] = tmp_b;
    min_heapify(a, b, smallest, n);
  }
}

int left_child(int idx) { return 2 * idx; }
int right_child(int idx) { return 2 * idx + 1; }
