#include <thread>
#include <iostream>
#include "sema.h"

static int max = 100;

static Semaphore oddSema(0);
static Semaphore evenSema(1);

void printEven() {
    int i = 0;
    while (i < max) {
        evenSema.wait();
        std::cout << i << std::endl;
        i += 2;
        oddSema.signal();

    }
}

void printOdd() {
    int i = 1;
    while (i < max) {
        oddSema.wait();
        std::cout << i << std::endl;
        i += 2;
        evenSema.signal();
    }
}

int main()
{
    std::thread tEven(printEven);
    std::thread tOdd(printOdd);
    tEven.join();
    tOdd.join();
    return 0;
}
