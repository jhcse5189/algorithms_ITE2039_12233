#include "dyn.h"

// TODO: compare running time.

// MAIN

int main(int argc, char* argv[]) {

    int n;
    std::cin >> n;

    std::cout << "fib(" << n << ") -> "
              << Fib::recursive(n) << std::endl;
    return 0;
}