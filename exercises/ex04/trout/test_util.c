#include <string.h>
#include "minunit.h"
#include "util.h"

int tests_run = 0;

static char *test0() {
    char *res = icmpcode_v4(0);
    char *exp = "network unreachable";
    char *message = "test failed";

    mu_assert(message, strcmp(res, exp) == 0);
    return NULL;
}

static char *run_tests() {
    mu_run_test(test0);
    return NULL;
}

int main() {
    char * result = run_tests();

    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    return result != 0;
}
