#include <stdio.h>

int x = 5;

void print_x() {
    printf("%i", x);
}

// Notes about optimization: With optimization enabled, the compiler only brings
// in variables necessary to the program output. For example, with line 15
// uncommented, it is necessary to compute the value of `y`, so the program
// needs `x` and `y` in memory. However, when that line is commented out, `y` is
// no longer needed (it's an unreferenced variable), so it is omitted.

int main() {
    int y = x + 1;
    printf("Hello, World!\n");
    //printf("%i", y);
    return 0;
}
