/*
 * String Manipulation Introduction Program (adding spaces between character elements)
 *
 * Sam Walsh 
 * March 21, 2023
 * 
 * This simple C program demonstrates basic string manipulation
 * It takes a predefined character array, inserts a space between each element, and prints the result.
 */

#include <stdio.h>
#include <string.h>

int main() {
    char input_string[] = "EEEManchester";  // Declare and initialize the character array
    int len = strlen(input_string);         // Calculate the length of the input string
    int new_len = len * 2;                  // Calculate the length of the new string with spaces

    char spaced_string[new_len + 1];        // Declare an array to store the new spaced string

    for (int i = 0; i < len; i++) {         // Iterate through the input string
        spaced_string[i * 2] = input_string[i];  // Copy the original character to the new array
        spaced_string[i * 2 + 1] = ' ';          // Insert a space after each character
    }

    spaced_string[new_len] = '\0';  // Add the null terminator at the end of the new string

    printf("Original string: %s\n", input_string);    // Print the original string
    printf("String with spaces: %s\n", spaced_string); // Print the spaced string

    return 0;
}