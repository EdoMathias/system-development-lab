/*
    reverse_words.c
    
    Purpose: Reads one line from stdin and reverses the letters of each word
    in-place. Whitespace characters are kept in place and in count.

    Method: The program scans a string from left to right in one pass using a scanning index,
    where whitespace is skipped, and for each word (a sub-string without whitespace),
    it saves the index of the first character, and continues the scan until it reaches a whitespace
    or the end of the string, where it then marks the second index on the character before the whitespace.
    Before the scan continues, it performs an in-place swap by using the two indices to swap
    the characters, moving the indices inwards until they meet.
    When they meet, it continues to scan the rest of the string until the end of it.

    Input: One line of text from stdin, keyboard or redirected file.

    Output: Prints the input string, the string as received by the
    function, and the string after reversal.
*/

#include <stdio.h>
#include <ctype.h>

/* Maximum characters read from a line, limited to 100 as it is a round and easy to remember number */
#define MAX_LENGTH 100

/*
    Reverses the characters of each word in str, in-place.
    Whitespace characters identified by isspace() are kept in place and in count.
    Prints str before and after the reversal.
*/
void reverse_words(char str[]);

int main(void) {

    int curr_char;
    char string[MAX_LENGTH + 1]; /* A string with MAX_LENGTH amount of characters and terminating '\0' */
    int index = 0;

    printf("Please enter an input of up to %d characters:\n", MAX_LENGTH);

    while (index < MAX_LENGTH && (curr_char = getchar()) != EOF && curr_char != '\n') {
        string[index] = (char)curr_char;
        index++;
    }

    /* Insert \0 to mark the end of the string */
    string[index] = '\0';

    printf("The Input string:\n");
    printf("%s\n", string);

    reverse_words(string);

    return 0;
}

void reverse_words(char str[]) {
    int index = 0;
    int first_char_index = index, last_char_index = index;

    printf("The string as received by the function:\n");
    printf("%s\n", str);

    while (str[index] != '\0') {
        /* Skip whitespace to get to the word */
        while (isspace(str[index])) {
            index++;
        }

        /* Reached the end and did not find any characters */
        if (str[index] == '\0') {
            break;
        }

        /* Mark first char of the current word */
        first_char_index = index;

        /* Find last char of current word */
        while (!isspace(str[index]) && str[index] != '\0') {
            index++;
        }

        /* Mark last char of the current word */
        last_char_index = index - 1;

        /* Swap outer characters marked by indices, and move inwards */
        while (first_char_index < last_char_index) {
            char temp_char = str[first_char_index];
            str[first_char_index] = str[last_char_index];
            str[last_char_index] = temp_char;

            first_char_index++;
            last_char_index--;
        }
    }

    printf("The string at the end of the function:\n");
    printf("%s\n", str);
}