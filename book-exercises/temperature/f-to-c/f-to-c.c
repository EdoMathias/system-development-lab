#include <stdio.h>

/* Prints Fahrenheit to Celsuis table for fahr = 0, 20, ..., 300 */

main() {
    float fahr, celsuis;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("Fahrenheit|Celsuis\n");
    while (fahr <= upper) {
        celsuis = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsuis);
        fahr = fahr + step;
    }
}