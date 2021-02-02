/**
 * cards.c: Prompts user for card and keeps track of the current count.
 * Author: Wesley Soo-Hoo (wsoohoo@olin.edu)
 * License: MIT License
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Prompts the user and gets the card. Puts the card name into the card_name
 * parameter.
 */
void get_card(char * card_name, char prompt[]) {
    puts(prompt);
    scanf("%2s", card_name);
}

/*
 * Parses the card_name parameter and returns the card value.
 */
int get_card_value(char card_name[]) {
    switch (card_name[0]) {
    case 'K':
    case 'Q':
    case 'J':
        return 10;
        break;
    case 'A':
        return 11;
        break;
    default:
        return atoi(card_name);
    }
}

/*
 * Returns the current count given the card value and the last count.
 */
int get_count(int value, int last_count) {
    if ((value > 2) && (value < 7)) {
        return last_count + 1;
    } else if (value == 10) {
        return last_count - 1;
    } else {
        return last_count;
    }
}

int main() {
    char card_name[3];
    int count = 0;
    int val = 0;
    while (card_name[0] != 'X') {
        get_card(card_name, "Put card value here");
        val = get_card_value(card_name);
        if ((val < 1) || (val > 10)) {
            if (card_name[0] != 'X') {
                puts("bad input");
            }
            continue;
        }

        count = get_count(val, count);
        printf("Current count: %i\n", count);
    }
    return 0;
}
