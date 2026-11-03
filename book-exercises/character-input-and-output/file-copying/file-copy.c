#include <stdio.h>

/* Copy input to output; 2nd version */
main() {
    int c;

    // C allows assignemnts in loop's conditions
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}