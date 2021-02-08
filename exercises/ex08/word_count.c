// word_count.c
// Exercise 8 from Olin College Software Systems
// Read a text file and count the frequency of each word
// Text files grabbed from the Gutenberg Project
// Usage: word_count [text_file.txt] -w [number_of_words]

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <unistd.h>
#include "frequency_analysis.h"


int main(int argc, char **argv) {
    // Process input arguments
    // [text_file.txt]
    // -w [words to display]
    char ch;
    int words_display = 10;  // Default display 10 words
    while ((ch = getopt(argc, argv, "w:")) != EOF) {
        switch (ch) {
        case 'w':
            words_display = atoi(optarg);

            if (DEBUG) {
                printf("Words to display: %i\n", words_display);
            }
        }
    }
    argc -= optind;
    argv += optind;

    FILE *book;
    if (argc != 1) {
        // Print usage and quit
        fprintf(stderr, "Correct usage:\n\tword_count [text_file.txt] -w [number_of_words]\n");
        exit(1);
    } else {
        char *filename = argv[0];
        book = fopen(filename, "r");
        if (book == NULL) {
            fprintf(stderr, "Invalid book! %s\n", filename);
            exit(1);
        }
    }

    if (DEBUG) {
        printf("book read: %p\n", book);
    }

    // Get words
    GSList *words = NULL;
    get_words_from_book(book, &words);

    // Run frequency analysis
    GSList *frequencies = NULL;
    get_words_frequency(words, &frequencies);


    // Display results
    print_words_frequency(frequencies, words_display); 

    // Free lists
    g_slist_free(words);
    g_slist_free(frequencies);
    return 0;
}

