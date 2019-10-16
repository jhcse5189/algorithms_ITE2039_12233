#include <iostream>
#include <cstdlib>      // For rand(), srand()
#include <ctime>        // For time(), clock()
#include <fstream>
#include <string>
#include <cstdio>

#define MAX_INPUT_SIZE 9999

/* Hybrid Quick Sort with Insertion Sort
     & Median of 3 Partitioning. (ch 7.4-5) */

// TODO: function naming convention. (ex. hybridQuickSort())
void hybrid_quick_sort(int* a, int p, int r);
int partition(int* a, int p, int r);
int median_of_3(int* arr, int i, int j);
void insertion_sort(int* a, int r);
void swap(int* a, int i, int j);


int main(int argc, char* argv[]) {

    // seed for median of 3.
    std::srand(std::time(NULL));

    clock_t start, end;
    float delay;

    int i, j;
    int* eltArr = new int[MAX_INPUT_SIZE];
    std::string inpath = "input2-1.txt";
    std::string outpath = "output2-1.txt";


    // read File
    std::ifstream inf(inpath);
    // TODO: why eof is issued?
    if (inf) {
        for (i = 0; !inf.eof(); i++)
            inf >> eltArr[i];
    }

    start = clock();
    hybrid_quick_sort(eltArr, 1, i - 1);
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

    int q;
    if (r + 1 <= 10) insertion_sort(a, r + 1);
    else {
        if (p < r) {
            q = partition(a, p, r);
            hybrid_quick_sort(a, p, q - 1);
            hybrid_quick_sort(a, q + 1, r);
        }
    }
}


int partition(int* a, int p, int r) {

    int i, j, tmp;
    int pivot = median_of_3(a, p-1 ,r);
    swap(a, pivot, r);

    i = p-1;
    for (j = p; j < r; j++) {
        if (a[j] <= a[r]) {
            i++;
            swap(a, i, j);
        }
    }

    // j == r,
    swap(a, i + 1, j);
    return i + 1;
}


int median_of_3(int* arr, int i, int j) {


    int a, b, c, median;
    
    a = i + std::rand() % (j-i+1);
    // std::cout << a << " ";

    do {
        b = i + std::rand() % (j-i+1);
    } while (b == a);
    // std::cout << b << " ";

    do {
        c = i + std::rand() % (j-i+1);
    } while (c == b || c == a);
    // std::cout << c << " " << std::endl;

    // std::cout << arr[a] << " "
    //           << arr[b] << " "
    //           << arr[c] << "\n";

    if ((arr[a] < arr[b] && arr[b] < arr[c]) || (arr[c] < arr[b] && arr[b] < arr[a])) return b;
    else if ((arr[b] < arr[a] && arr[a] < arr[c]) || (arr[c] < arr[a] && arr[a] < arr[b])) return c;
    else return c;
}


void insertion_sort(int* a, int r) {

    int i, j, tmp;
    for (i = 1; i < r; i++) {

        for (j = i; j > 0; j--) {

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