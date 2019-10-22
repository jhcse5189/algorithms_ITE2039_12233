#ifndef __DYN_H__
#define __DYN_H__

#include <iostream>

class Fib {
private:
    int n;
public:
    Fib(int n);
    int recursive(int n);
};

#endif /* __DYN_H__ */