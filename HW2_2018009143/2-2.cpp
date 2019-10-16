#include <iostream>

/* Rod Cutting. (ch 15.1) */

int main(int argc, char* argv[]) {

    int rodLen;
    // TODO: replace dynamic alloc. by calc.
    int values[5];
    std::string inpath = "input2-2.txt";

    /* INPUT */
    // line 1. length of rod
    // line 2. value of each length.

    // read File
    std::ifstream inf(inpath);

    if (inf) {
        inf >> rodLen;
        for (i = 0; !inf.eof(); i++)
            inf >> values[i];
    }

    /* OUTPUT */
    // line 1. When Maximum profit,
    // line 2. lengths of rods order by asc;


}