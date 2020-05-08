// word_count.h
// Function definitions for word_count.c

#ifndef FREQ_ANALYSIS_H
#define FREQ_ANALYSIS_H

#include <glib.h>

#define DEBUG 0

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

void get_words_from_book(FILE *book, GSList **words);
void get_words_frequency(GSList *words, GSList **frequencies);
void print_words_frequency(GSList *frequencies, int num_print);

gint compare_strings(gconstpointer i1, gconstpointer i2);
gint compare_frequencies(gconstpointer i1, gconstpointer i2);
#endif
