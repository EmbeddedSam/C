/*
 * String Manipulation Introduction Program
 *
 * Sam Walsh 
 * March 21, 2023
 * 
 * This simple C program demonstrates how a character array can hold a string. 
 * It also introduces the strlen() function from <string.h> which returns the length of the string. 
 * The program takes a predefined character array "input_string" and copies it to another character array "copied_string", then prints both strings.
 * For more information on strlen() see here https://www.ibm.com/docs/ssw_ibm_i_71/rtref/strlen.htm 
 * Note IBM provide excellent documentation on most of the typical C functions,if you are unsure on any other functions, simply search on the website in the link above
 */

#include <stdio.h>
#include <string.h>

int main() {
    char input_string[] = "EEE > MACE!";    // Declare and initialise the character array
    int len = strlen(input_string);         // Calculate the length of the input string

    char copied_string[len + 1];            // Declare an array to store the copied string

    for (int i = 0; i <= len; i++) {        // Iterate through the input string (including null terminator)
        copied_string[i] = input_string[i]; // Copy the character to the new array
    }

    printf("Original string: %s\n", input_string);  // Print the original string
    printf("Copied string: %s\n", copied_string);   // Print the copied string

    return 0;
}
