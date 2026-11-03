#include <stdio.h>

int main() {
    int curr_char;
    
    while ((curr_char = getchar()) != EOF) {
        if (curr_char == '\t') {
            putchar('\\');
            putchar('t');
        }
        else if (curr_char == '\b') {
            putchar('\\');
            putchar('b');
        }
        else if (curr_char == '\\') {
            putchar('\\');
            putchar('\\');
        }
        else {
            putchar(curr_char);
        }

    }
    return 0;
}