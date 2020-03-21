#include <stdio.h>


int main() {
    int a = 3;
    int b = 4;
    int c = a + b;
    printf("c = %d\n", c);

    if (c%2 == 0) {
        printf("c is even\n");
    } else {
        printf("c is odd\n");
    }
}
