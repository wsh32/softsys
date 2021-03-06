/**
 * tee.c: Implementation of tee
 * Passes output to stdout and writes to files
 */


#include <stdio.h>
#include <unistd.h>

#define BUF_SIZE 80
#define DEBUG 1  // enable debug messages printed

int main(int argc, char *argv[]) {
    // get cmd line arguments
    char ch;
    int append = 0;
    while ((ch = getopt(argc, argv, "a")) != EOF) {
        switch(ch) {
        case 'a':
            append = 1;
            break;
        }
    }

    argc -= optind;
    argv += optind;

    // open file with append if requested
    FILE *out_file;
    if (DEBUG) {
        printf("File name: %s\n", argv[0]);
    }
    if (append) {
        out_file = fopen(argv[0], "a");
    } else {
        out_file = fopen(argv[0], "w");
    }

    // write to file and print
    char buf[BUF_SIZE];
    while (fgets(buf, BUF_SIZE, stdin) != NULL) {
        printf(buf);
        fprintf(out_file, "%s", buf);
    }

    fclose(out_file);
}
