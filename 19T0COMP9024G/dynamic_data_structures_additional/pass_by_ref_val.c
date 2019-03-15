// Simple example to illustrate pass by value and reference
// Ashesh Mahidadia  - ashesh@cse.unsw.edu.au
// 14 August 2018

#include <stdio.h>

void f1(int a, int *p) {
    a = a + 5;
    *p = *p + 7;
}

int main(int argc, char *argv[]) {
    int x = 25;
    int y = 33;

    printf("Before calling f1: x=%d y=%d\n", x, y);

    f1(x, &y);

    printf("After calling f1:  x=%d y=%d\n", x, y);
    // x is unchanged, y changed 

    return 0;
}
