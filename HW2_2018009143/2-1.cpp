#include <iostream>
#include <cstdlib>      // For rand() and srand()
#include <ctime>        // For time()
#include <fstream>
#include <string>

#define MAX_INPUT_SIZE 9999

/* Hybrid Quick Sort with Insertion Sort
     & Median of 3 Partitioning. (ch 7.4-5) */

int* quick_sort(int* a, int p, int r);
int partition(int* a, int p, int r);


int main(int argc, char* argv[]) {

    int i, j;
    int* eltArr = new int[MAX_INPUT_SIZE];
    std::string inpath = "input2-1.txt";
    std::string outpath = "output2-1.txt";


    // read File
    std::ifstream inf(inpath);

    if (inf) {
        for (i = 0; !inf.eof(); i++) {
            inf >> eltArr[i];
            std::cout << "[" << i << "]: " << eltArr[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "[15]: " << eltArr[i] << "\n";
    }

    //quick_sort;
    std::cout << "[15]: " << eltArr[i] << "\n";

    /*
    // write File
    std::ofstream output("output2-1.txt");
    if (output.is_open()) {

        for (j = 0; j < i; j++)
            output << eltArr[i] << " "; 
        std::cout << "done." << "\n";
    }
    */
    delete[] eltArr;

    return 0;
}

int* quick_sort(int* a, int p, int r) {

    int q;
    if (p < r) {
        q = partition(a, p, r);
        quick_sort(a, p, q - 1);
        quick_sort(a, q + 1, r);
    }
    return a;
}

int partition(int* a, int p, int r) {
    
    std::srand(std::time(0));
    int rand_idx = std::rand() % 10;
    std::cout << "Random value on [0, " << MAX_INPUT_SIZE << "]: "
             << rand_idx << '\n';

    return 0;
}