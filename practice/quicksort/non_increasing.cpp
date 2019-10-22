#include <iostream>

void quick_nonincrease(int* a, int p, int r);
int partion(int* a, int p, int r);

int main(int argc, char* argv[]) {

    int i;
    int a[7] = { 2, 8, 7, 1, 3, 5, 6 };

    quick_nonincrease(a, 0, 6);

    for (i = 0; i < 7; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    return 0;
}

void quick_nonincrease(int* a, int p, int r) {

    int q;
    if (p < r) {
        q = partion(a, p, r);
        quick_nonincrease(a, p, q-1);
        quick_nonincrease(a, q+1, r);
    }
}

int partion(int* a, int p, int r) {

    int i, j, x, tmp;
    x = a[r];

    i = p-1;
    for (j = p; j < r; j++) {
        if (a[j] > x) { // <= for asc.
            i = i + 1;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    tmp = a[i+1];
    a[i+1] = a[j];
    a[j] = tmp;
    return i; // i + 1 for asc.
}