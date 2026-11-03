#include <stdio.h>

int main() {
    int curr_char;
    long blanks_count = 0, tabs_count = 0, newlines_count = 0;
    
    while ((curr_char = getchar()) != EOF) {
        if (curr_char == ' ') {
            ++blanks_count;
        }
        if (curr_char == '\t') {
            ++tabs_count;
        }
        if (curr_char == '\n') {
            ++newlines_count;
        }
    }
    printf("Blanks count: %ld\nTabs count: %ld\nNewlines count: %ld\n", blanks_count, tabs_count, newlines_count);
    return 0;
}