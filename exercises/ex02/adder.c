/**
 * adder.c: Takes in integers from stdin and prints the sum.
 *
 * Author: Wesley Soo-Hoo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_INPUT  10  // Maximum length of the string input allowed
#define MAX_INPUTS      5  // Maximum number of inputs allowed

int add_numbers(int nums_to_add[], int size_nums) {
    /**
     * add_numbers: Returns the sum of the numbers in the input array
     */
    int sum = 0;
    for (int i = 0; i < size_nums; i++) {
        sum += nums_to_add[i];
    }
    return sum;
}

int main() {
    char str_in[MAX_SIZE_INPUT];
    int nums_add[MAX_INPUTS];
    int nums_add_counter = 0;
    // continuously read str in until ctrl d
    while(fgets(str_in, MAX_SIZE_INPUT, stdin) != NULL) {
        // if not line ending get number
        int int_in = atoi(str_in);
        nums_add[nums_add_counter] = int_in;
        nums_add_counter++;

        if (nums_add_counter == MAX_INPUTS) {
            break;
        }
    }
    int sum = add_numbers(nums_add, nums_add_counter);
    printf("Sum of the numbers: %i\n", sum);
    return 0;
}
