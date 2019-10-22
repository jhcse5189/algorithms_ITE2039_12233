#include <iostream>
#include <fstream>
#include <tuple>
#include <iomanip>

#define MAX(X, Y) ((X) < (Y)) ? (Y) : (X) 
#define TMIN_INT -2147483648

int r[100], s[100];


/* Rod Cutting. (ch 15.1) */


/* bottom-up */
//std::tuple<int*, int*>
int extended_bottom_up_cut_rod(int n, int* p);
void print_cut_rod_solution(int n);//, int* p);
int bottom_up_cut_rod(int n, int* p);

/* top-down */
int memoized_cut_rod(int n, int* p);
int memoized_cut_rod_aux(int n, int* p, int* r);

// naive.
int recursive_top_down_cut_rod(int n, int* p);


int main(int argc, char* argv[]) {

    int n_rodLen, i;
    // TODO: replace dynamic alloc. by calc.
    int* prices;
    std::string inpath = "input2-2.txt";


    /* INPUT */
    // line 1. length of rod. [1, 100]
    // line 2. value of each length ORDER BY ASC;

    // read File
    std::ifstream inf(inpath);

    if (inf) {
        inf >> n_rodLen;
        prices = new int[n_rodLen + 1];
        
        prices[0] = 0;
        for (i = 1; !inf.eof(); i++)
            inf >> prices[i];
    }

    /* OUTPUT */
    // line 1. When we get maximum value,
    // line 2. the length of rods ORDER BY ASC;

    // std::cout << recursive_top_down_cut_rod(n_rodLen, prices) << std::endl;
    // std::cout << memoized_cut_rod(n_rodLen, prices) << std::endl;
    // std::cout << bottom_up_cut_rod(n_rodLen, prices) << std::endl;

    // TODO: imple. print... from getting pair of array...
    //print_cut_rod_solution(n_rodLen, prices);
    //std::cout << std::endl;

    std::cout << extended_bottom_up_cut_rod(n_rodLen, prices) << std::endl;
    print_cut_rod_solution(n_rodLen);

    return 0;
}


//std::tuple<int*, int*>
int extended_bottom_up_cut_rod(int n, int* p) {

    int i, j, q;
    //int r[n + 1], s[n + 1] = { 0, };
    r[0] = 0;

    for (j = 1; j <= n; j++) {
        q = TMIN_INT;
        for (i = 1; i <= j; i++) {
            if (q < p[i] + r[j-i])
                q = p[i] + r[j-i];
                s[j] = i;
        }
        r[j] = q;
    }
    return r[n];
    /*
    //std::tuple<int*, int*> rs = std::make_tuple(r, s);
    //return rs;

    std::cout << "r[i]: ";
    for (i = 0; i <= n; i++) {
        std::cout << std::setw(2) << r[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "s[i]: ";
    for (i = 0; i <= n; i++) {
        std::cout  << std::setw(2) << s[i] << " ";
    }
    std::cout << std::endl;
    */
}

void print_cut_rod_solution(int n) { //, int* p) {

    do {
        std::cout << s[n] << " ";
    } while ((n -= s[n]) > 0);
    // int r[n + 1], s[n + 1];
    // std::tie(r, s) = extended_bottom_up_cut_rod(n, p);

    // while (n > 0) {
    //     std::cout << s[n] << " ";
    //     n = n -s[n];
    // }
    
}


int bottom_up_cut_rod(int n, int* p) {

    int r[n + 1], q, i, j;
    r[0] = 0;

    for (j = 1; j <= n; j++) {
        q = TMIN_INT;
        for (i = 1; i <= j; i++)
            q = MAX(q, p[i] + r[j-i]);
        r[j] = q;
    }
    return r[n];
}


int memoized_cut_rod(int n, int* p) {
    
    int r[n + 1], i;
    for (i = 1; i <= n; i++)
        r[i] = TMIN_INT;
    return memoized_cut_rod_aux(n, p, r);
}


int memoized_cut_rod_aux(int n, int* p, int* r) {

    int q, i;
    if (r[n] >= 0)
        return r[n];
    if (n == 0)
        q = 0;
    else q = TMIN_INT;
        for (i = 1; i <= n; i++)
            q = MAX(q, p[i] + memoized_cut_rod_aux(n - i, p, r));

    r[n] = q;
    return q;
}


int recursive_top_down_cut_rod(int n, int* p) {

    int i;
    int q = TMIN_INT;

    if (n == 0) return 0;
    for (i = 1; i <= n; i++)
        q = MAX(q, p[i] + recursive_top_down_cut_rod(n - i, p));
    return q;
}