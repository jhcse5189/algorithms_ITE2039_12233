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
int median_of_3(int* a, int p, int r);
void insertion_sort(int* a, int r);



int main(int argc, char* argv[]) {

    // seed for median of 3.
    std::srand(std::time(NULL));

    clock_t start, end;
    double d;

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
    std::cout << "i: " << i << std::endl;
    


    start = clock();
    std::cout << "ready?... press the enter...\n";
    std::cin.ignore();
    hybrid_quick_sort(eltArr, 1, i - 1);

    end = clock();
    //delay = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << start << " " << end << std::endl;
    printf("%lf\n", (double)(end - start) / CLOCKS_PER_SEC);

    // write File
    std::ofstream output("output2-1.txt");
    
    if (output.is_open()) {

        for (j = 0; j < i; j++)
            output << eltArr[j] << " ";
        output << "\n" << (double)(end - start) / CLOCKS_PER_SEC << " s" << "\n";
    }
    
    delete[] eltArr;
    return 0;
}


void hybrid_quick_sort(int* a, int p, int r) {

    int q;
    if (r + 1 <= 10) {
        insertion_sort(a, r + 1);
    } 

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
    int pivot = median_of_3(a, p ,r);

    tmp = a[r];
    a[r] = a[pivot];
    a[pivot] = tmp;

    i = p-1;
    for (j = p; j < r; j++) {
        if (a[j] <= a[r]) {
            i++;
            tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
        }
    }
    // j == r,
    tmp = a[j];
    a[j] = a[i + 1];
    a[i + 1] = tmp;
    return i + 1;
}


int median_of_3(int* a, int p, int r) {

/*
    
    int rand_idx = std::rand() % 10;
    std::cout << "Random value on [0, " << MAX_INPUT_SIZE << "]: "
             << rand_idx << '\n';
*/


    return r;
}

void insertion_sort(int* a, int r) {

    int i, j, tmp;
    for (i = 1; i < r; i++) {

        for (j = i; j > 0; j--) {

            if (a[j-1] > a[j]) {
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
            }
            else break;
        }
    }
}