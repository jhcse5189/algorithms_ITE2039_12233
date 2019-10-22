#include <iostream>

void counting_sort(int* a, int* b, int k);

int main(int argc, char* argv[]) {

    int i;
    int a[] = { 0, 6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2 };
    int b[12] = { 0, };

    counting_sort(a, b, 6);

    for (i = 1; i < 12; i++) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

void counting_sort(int* a, int* b, int k) {

    int i, j;
    int c[k + 1] = { 0, };

    for (i = 1; i <= 11; i++)
        c[a[i]] = c[a[i]] + 1;

    for (i = 1; i <= k; i++)
        c[i] = c[i] + c[i-1];

    for (i = 11; i >= 1; i--) {
        b[c[a[i]]] = a[i];
        c[a[i]] = c[a[i]] - 1;
    }
}