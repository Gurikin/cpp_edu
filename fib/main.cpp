#include <iostream>
#include <array>
#include <stdio.h>

int main() {
    std::array<size_t, 2> lastFibonacci = {0, 1};
    size_t index = 0;
    std::cin >> index;
    size_t sourceIndex = index;

    for (/**/;index > 2; index--) {
        size_t next = lastFibonacci[0] + lastFibonacci[1];
        lastFibonacci[0] = lastFibonacci[1];
        lastFibonacci[1] = next;
    }

    printf("Fibonacci[%ld] = %ld\n", sourceIndex, lastFibonacci[sourceIndex == 0 ? 0 : 1]);
}