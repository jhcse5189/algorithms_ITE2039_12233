#include <iostream>

void tail_recursive_quick(int* a, int p, int r);
int partion(int* a, int p, int r);

int main(int argc, char* argv[]) {

    int i;
    int a[7] = { 2, 8, 7, 1, 3, 5, 6 };

    tail_recursive_quick(a, 0, 6);

    for (i = 0; i < 7; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    return 0;
}

void tail_recursive_quick(int* a, int p, int r) {

    int q;
    if (p < r) {
        // Partion and sort left subarray
        q = partion(a, p, r);
        tail_recursive_quick(a, p, q-1);
        p = q + 1;
    }
}

int partion(int* a, int p, int r) {

    int i, j, x, tmp;
    x = a[r];

    i = p-1;
    for (j = p; j < r; j++) {
        if (a[j] <= x) {
            i = i + 1;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    tmp = a[i+1];
    a[i+1] = a[j];
    a[j] = tmp;
    std::cout << "partition returns " << i + 1 << "." << std::endl;
    return i + 1;
}