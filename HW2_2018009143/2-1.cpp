#include <iostream>
#include <cstdlib>      // For rand(), srand()
#include <ctime>        // For time(), clock()
#include <fstream>
#include <string>
#include <cstdio>

/* Hybrid Quick Sort with Insertion Sort
     & Median of 3 Partitioning. (ch 7.4-5) */

// TODO: function naming convention. (ex. hybridQuickSort())
void hybrid_quick_sort(int* a, int p, int r);
int partition(int* a, int p, int r);
int median_of_3(int* arr, int i, int j);
void insertion_sort(int* a, int p, int r);
void swap(int* a, int i, int j);


int main(int argc, char* argv[]) {

    // seed for median of 3.
    std::srand(std::time(NULL));

    clock_t start, end;
    float delay;

    int i, j, key;
    int* eltArr = new int[200000];
    std::string inpath = "input_100000.txt";
    std::string outpath = "output2-1.txt";


    // read File
    std::ifstream inf(inpath);
    // TODO: why eof is issued?
    i = 0;
    while (inf >> key) {
        eltArr[i] = key;
        i++;
    }
    std::cout << i << std::endl;

    start = clock();
    hybrid_quick_sort(eltArr, 0, i-1);
    end = clock();

    delay = (float)(end - start) / CLOCKS_PER_SEC;

    // write File
    std::ofstream output("output2-1.txt");
    if (output.is_open()) {

        for (j = 0; j < i; j++)
            output << eltArr[j] << " ";
        output << "\n" << std::fixed << delay << " s" << "\n";
    }

    delete[] eltArr;
    return 0;
}


void hybrid_quick_sort(int* a, int p, int r) {

    if (r - p < 10) insertion_sort(a, p, r);
    else {
        if (p < r) {
            int q = partition(a, p, r);
            hybrid_quick_sort(a, p, q - 1);
            hybrid_quick_sort(a, q + 1, r);
        }
    }
}


int partition(int* a, int p, int r) {

    int i, j;
    int pivot = median_of_3(a, p, r);
    swap(a, pivot, r);

    i = p-1;
    for (j = p; j < r; j++) {
        if (a[j] <= a[r]) {
            i++;
            swap(a, i, j);
        }
    }

    swap(a, i + 1, j);
    return i + 1;
}


int median_of_3(int* arr, int i, int j) {


    int a, b, c, median;
    
    a = i + std::rand() % (j-i+1);

    do {
        b = i + std::rand() % (j-i+1);
    } while (b == a);

    do {
        c = i + std::rand() % (j-i+1);
    } while (c == b || c == a);

    if ((arr[a] < arr[b] && arr[b] < arr[c]) || (arr[c] < arr[b] && arr[b] < arr[a])) return b;
    else if ((arr[b] < arr[a] && arr[a] < arr[c]) || (arr[c] < arr[a] && arr[a] < arr[b])) return c;
    else return c;
}


void insertion_sort(int* a, int p, int r) {

    int i, j, tmp;
    for (i = p + 1; i < r; i++) {

        for (j = i; j > p; j--) {

            if (a[j-1] > a[j])
                swap(a, j-1, j);
            else break;
        }
    }
}


void swap(int* a, int i, int j) {

    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}