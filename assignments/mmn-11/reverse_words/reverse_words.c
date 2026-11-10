/*
 reverse_words.c
    
    Purpose: Reads one line from stdin and reverses the letters of each word
    in place, keeping every whitespace character where it was.

    Method: TODO: one or two sentences. A word is a run of non-whitespace
    characters. Describe the single pass and how the swap is done.

    Input: One line of text (ASCII) from stdin, keyboard or redirected file.

    Output: To stdout: the input string, the string as received by the
    function, and the string after the change.
*/

#include <stdio.h>
#include <ctype.h>

/*
    Reverses the characters of each word in a given string in-place.
    White-space characters identified by isspace() are kept in place and in count.
*/
void reverse_words(char str[]);

int main(void) {

    int curr_char;
    char string[256];
    int index = 0;

    while ((curr_char = getchar()) != EOF && curr_char != '\n' && index < 256) {
        string[index] = (char)curr_char;
        index++;
    }

    string[index] = '\0';

    printf("The Input string:\n");
    printf("%s\n", string);

    reverse_words(string);

    return 0;
}

void reverse_words(char str[]) {
    int index = 0;
    int first_char_index = index, last_char_index = index;

    /* Print the string received by the function */
    printf("The string as received by the function:\n");
    printf("%s\n", str);

    /* Reverse the string */
    while (str[index] != '\0') {
        /* Skip spaces and tabs */
        while (isspace(str[index])) {
            index++;
        }

        /* Edge case: whitespace only string */
        if (str[index] == '\0') {
            break;
        }

        /* Flag index of first char of the word */
        first_char_index = index;

        /* Find last char of current word */
        while (!isspace(str[index]) && str[index] != '\0') {
            index++;
        }

        last_char_index = index - 1;

        /* Reverse current word */
        while (first_char_index < last_char_index) {
            char temp_char = str[first_char_index];
            str[first_char_index] = str[last_char_index];
            str[last_char_index] = temp_char;

            first_char_index++;
            last_char_index--;
        }
    }

    /* Print the string post reversal */
    printf("The string at the end of the function:\n");
    printf("%s\n", str);
}