/*
 * String Manipulation Introduction Program (Using Pointers and While Loop)
 *
 * Sam Walsh 
 * March 21, 2023
 * 
 * This simple C program demonstrates how pointers can be used to point to strings. 
 * It also uses the strlen() function from <string.h> which returns the length of the string. 
 * The program takes a predefined constant character pointer "input_string" and copies it to a local buffer using a character pointer "copied_string", then prints both strings.
 * The copying process uses a while loop to check for the null terminator instead of a for loop.
 * For more information on strlen() see here https://www.ibm.com/docs/ssw_ibm_i_71/rtref/strlen.htm 
 * Note IBM provide excellent documentation on most of the typical C functions, if you are unsure on any other functions, simply search on the website in the link above
 */

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

int main() {
    const char* input_string = "EEE > CompiSci!";    // Declare and initialize the constant character pointer
    int len = strlen(input_string);             // Calculate the length of the input string

    char copied_buffer[MAX_BUFFER_SIZE];        // Declare a local buffer for the copied string
    char* copied_ptr = copied_buffer;           // Declare a character pointer pointing to the local buffer

    int i = 0;                                  // Initialize a counter
    while (input_string[i] != '\0') {           // Iterate through the input string until null terminator is found
        copied_ptr[i] = input_string[i];        // Copy the character to the buffer
        i++;                                    // Increment the counter
    }
    copied_ptr[i] = '\0';                       // Add the null terminator to the copied string

    printf("Original string: %s\n", input_string);  // Print the original string
    printf("Copied string: %s\n", copied_ptr);      // Print the copied string

    return 0;
}
