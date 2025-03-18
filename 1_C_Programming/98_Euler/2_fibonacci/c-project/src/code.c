// This file contains the C source code for the project. It includes the implementation of the Fibonacci sequence and a function to calculate the sum of even-valued terms.

#include <stdio.h>

#define MAX_VALUE 4000000

int findSum() {
    int a = 1, b = 2, sum = 0;

    while (b <= MAX_VALUE) {
        if (b % 2 == 0) {
            sum += b;
        }
        int next = a + b;
        a = b;
        b = next;
    }

    return sum;
}

int main(int argc, char* argv[]) {
    int result = findSum();
    printf("The sum of the even-valued terms in the Fibonacci sequence not exceeding four million is: %d\n", result);
    return 0;
}