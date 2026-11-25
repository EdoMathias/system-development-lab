/*
    count_ones.c
    
    Purpose: Reads an unsigned long number from the user and prints it in both
    base 10 and base 2 (leading zeros included).
    Then it counts the number of set bits, and prints if that count is EVEN or ODD.

    Method: It reads each bit by shifting right the unsigned long number based on
    the bit's position, then masking it using 1 ((num >> i) & 1).
    Bits are scanned from the leftmost bit to the rightmost bit.
    The number of bits is computed using (sizeof(unsigned long) * CHAR_BIT) so the
    total number of bits is based on the current system.

    Input: A single unsigned long number from stdin, keyboard or redirected file.
    It assumes a valid input, as answered by the instructor in the course forum.

    Output: Prints the number in base 10, base 2, the number of set bits and
    whether that count is EVEN or ODD.
*/

#include <stdio.h>
#include <limits.h>

/* Total number of bits in an unsigned long int on the current system */
#define NUM_OF_BITS_INT (sizeof(unsigned long int) * CHAR_BIT)

/*
    Returns the number of set bits of a given unsigned long int
*/
int count_ones(unsigned long int num);

int main(void) {

    unsigned long int starting_num;
    int num_of_set_bits = 0;
    int curr_bit = 0;
    int index;

    printf("Please enter an unsigned long number: ");

    scanf("%lu", &starting_num);

    printf("Original number in base 10: %lu\n", starting_num);

    /* Print as binary, starting from the leftmost bit */
    printf("Original number in base 2:\n");
    for (index = (NUM_OF_BITS_INT - 1); index >= 0; index--) {
        curr_bit = (starting_num >> index) & 1;
        printf("%i", curr_bit);
    }
    printf("\n");

    num_of_set_bits = count_ones(starting_num);

    printf("Total set bits (1s): %i\n", num_of_set_bits);
    printf("The count of set bits is %s.\n", (num_of_set_bits % 2) == 0 ? "EVEN" : "ODD");

    return 0;
}

int count_ones(unsigned long int num) {
    int num_of_set_bits = 0;
    int curr_bit = 0;
    int index;

    for (index = (NUM_OF_BITS_INT - 1); index >= 0; index--) {
        curr_bit = (num >> index) & 1;

        if (curr_bit == 1) {
            num_of_set_bits++;
        }
    }

    return num_of_set_bits;
}