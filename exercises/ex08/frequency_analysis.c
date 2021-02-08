// frequency_analysis.c
// Helper functions for word_count.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <glib.h>
#include "frequency_analysis.h"

/**
 * Gets list of words from a text file
 * Params:
 * - FILE *book: Pointer to a text file
 * - GSList **words: Pointer to a GSList to store the words
 *                  in with datatype char*
 */
void get_words_from_book(FILE *book, GSList **words) {
    char buff[80];  // 79 letter word max?
    while (fscanf(book, "%24s", buff) == 1) {
        if (DEBUG) {
            printf("%s\n", buff);
        }
        char *buff_copy = malloc(sizeof(char) * strlen(buff));
        reformat_string_lower_az(buff, buff_copy);
        *words = g_slist_append(*words, buff_copy);
    }

    if (DEBUG) {
        GSList *current_word = *words;
        printf("Words in list:\n");
        while (current_word != NULL) {
            printf("%s\n", (char*) current_word->data);
            current_word = current_word->next;
        }
        printf("\n");
    }
}

/**
 * Runs frequency analysis and saves data
 * Params:
 * - GSList *words: List of words with datatype char*
 * - GSList **frequencies: List of word frequencies with
 *                        datatype WordFrequency
 */
void get_words_frequency(GSList *words, GSList **frequencies) {
    while (words != NULL) {
        char *current_word = (char*) words->data;
        if (DEBUG == 1) {
            printf("%s\n", current_word);
        }
        // Find number of occurances and remove from list
        int initial_length = g_slist_length(words);
        // Remove all cases
        GSList *found_element; 
        while (1) {
            found_element = g_slist_find_custom(words, current_word, compare_strings);
            if (found_element == NULL) {
                break;
            }
            words = g_slist_remove(words, found_element->data);
        }
        int final_length = g_slist_length(words);
        int occurances = initial_length - final_length;
        if (DEBUG == 1) {
            printf("Word: %s, Init: %i, End: %i, Freq: %i\n", current_word, initial_length, final_length, occurances);
        }

        // Add data to frequencies
        WordFrequency *freq = malloc(sizeof(WordFrequency));
        freq->word = current_word;
        freq->frequency = occurances;
        *frequencies = g_slist_append(*frequencies, freq);
    }
}

/**
 * Prints the results from the frequency analysis
 * Params:
 * - GSList *freqencies: List of word frequencies with datatype
 *                       WordFrequency
 * - int num_print: Number of data points to print
 */
void print_words_frequency(GSList *frequencies, int num_print) {
    frequencies = g_slist_sort(frequencies, compare_frequencies);
    for (int i = 0; i < num_print; i++) {
        if (frequencies == NULL) {
            break;
        }
        WordFrequency *current_word = (WordFrequency*) frequencies->data;
        printf("Word: %s, Number of cases: %i\n", current_word->word, current_word->frequency);
        frequencies = frequencies->next;
    }
}


void reformat_string_lower_az(char *src, char *out) {
    for(; *src; ++src) {
        if (isupper((unsigned char) *src)) {
            *out++ = tolower((unsigned char) *src);
        } else if (islower((unsigned char) *src)) {
            *out++ = (unsigned char) *src;
        }
    }
    *out = 0;
}

/**
 * Compares strings regardless of case
 */
gint compare_strings(gconstpointer i1, gconstpointer i2) {
    return g_ascii_strcasecmp(i1, i2);
}

/**
 * Compares frequencies to place in descending order
 */
gint compare_frequencies(gconstpointer i1, gconstpointer i2) {
    WordFrequency *freq1 = (WordFrequency*) i1;
    WordFrequency *freq2 = (WordFrequency*) i2;
    return freq2->frequency - freq1->frequency; 
}
