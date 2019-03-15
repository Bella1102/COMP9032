// Simple example to illustrate how to modify an array passed 
// as an argument to a function.
//
// Ashesh Mahidadia  - ashesh@cse.unsw.edu.au
// 14 August 2018

#include <stdio.h>

void addGST(double a[], int size) {
    int i = 0;
    while(i<size){
        a[i] = 1.1 * a[i];
        i++;   
    }
}

void printArray(double a[], int size){

    int i = 0;
    while(i<size){
        printf("%10.2lf ", a[i]); 
        i++;   
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    double values[] = { 25.0, 32.5, 12.25, 52.50} ;

    printf("Before calling addGST: "); 
    printArray(values, 4); 

    addGST( values , 4 );

    printf("After calling addGST:  "); 
    printArray(values, 4); 

    return 0;
}
