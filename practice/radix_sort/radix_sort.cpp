#include <iostream>

int getMax(int a[], int n);
void radix_sort(int* a, int n);
void counting_sort(int* a, int n, int exp);

int main(int argc, char* argv[]) {

    int a[] = { 0, 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(a) / sizeof(a[0]); //9

    std::cout << "pung.\n";

    radix_sort(a, n-1);

    std::cout << "pung!\n";

    for (int i = 1; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

int getMax(int a[], int n) {

    int mx = a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i] > mx)
            mx = a[i];
    }
    std::cout << "pung in get\n";
    return mx;
}

void radix_sort(int a[], int n) {

    int m = getMax(a, n);
    std::cout << m << "\n";

    for (int exp = 1; m / exp > 0; exp *= 10) {
        std::cout << "pung before count.\n";
        counting_sort(a, n, exp);
    }
}

void counting_sort(int a[], int n, int exp) {

    int i;
    int output[n+1];
    int c[11] = { 0, };

    std::cout << "pung in count\n";

    for (i = 1; i <= n; i++)
        c[ (a[i]/exp)%10 ]++;

    for (i = 1; i <= 10; i++)
        c[i] = c[i] + c[i-1];

    for (i = n; i >= 1; i--) {
        output[c[ (a[i]/exp)%10 ]] = a[i];
        c[ (a[i]/exp)%10 ]--;
    }

    for (i = 1; i <= n; i++)
        a[i] = output[i];
}