/*
    count_ones.c
    
    Purpose: 

    Method: 

    Input: ...
    assumes valid input, as answered by the instructor in the course forum.

    Output: 
*/

#include <stdio.h>
#include <limits.h> /* Used for CHAR_BIT to not assume the byte size */

int count_ones(unsigned long int num);

int main(void) {

    unsigned long int starting_num;
    int num_of_set_bits = 0;

    printf("Please enter an unsigned long number:\n");

    scanf("%lu", &starting_num);

    printf("Original number in base 10: %lu\n", starting_num);

    num_of_set_bits = count_ones(starting_num);

    printf("\nTotal set bits (1s): %i\n", num_of_set_bits);
    printf("The count of set bits is %s.\n", (num_of_set_bits % 2) == 0 ? "EVEN" : "ODD");

    return 0;
}

int count_ones(unsigned long int num) {
    /* Get the number of bits in an unsigned long int */
    int num_of_bits_int = sizeof(unsigned long int) * CHAR_BIT;
    int num_of_set_bits = 0;
    int curr_bit = 0;
    int index;

    /* Convert num to base 2 */
    printf("Original number in base 2:\n");
    for (index = num_of_bits_int - 1; index >= 0; index--) {
        curr_bit = (num >> index) & 1;
        printf("%i", curr_bit);

        if (curr_bit == 1) {
            num_of_set_bits++;
        }
    }

    return num_of_set_bits;
}