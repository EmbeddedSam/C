/*
 * String length calculator and reverser using pointers and character arrays 
 *
 * Sam Walsh 
 * March 21, 2023
 * 
 * This C program again demonstrates string manipulation using pointers and char arrays.
 * The program takes a string, reverses it, and prints the original and reversed strings.
 * It also calculates the length of the string.
 * This time the code does not make use of any <string.h> functions. The functions from this header file are achieved manually.
 */

#include <stdio.h>

// Function to calculate the length of a string
int str_length(const char *str) {
    int len = 0;
    while (*str != '\0') {  // Iterate through the string until the null terminator is found
        len++;              // Increment the length
        str++;              // Move the pointer to the next character
    }
    return len;
}

// Function to reverse a string
void reverse_string(char *str) {
    int len = str_length(str);          // Get the length of the string
    for (int i = 0; i < len / 2; i++) {  // Iterate through half of the string
        char temp = *(str + i);          // Store the current character
        *(str + i) = *(str + len - 1 - i); // Swap the characters
        *(str + len - 1 - i) = temp;     // Assign the stored character
    }
}

int main() {
    char input_string[] = "Reverse me";  // Declare and initialize the char array

    printf("Original string: %s\n", input_string);  // Print the original string

    reverse_string(input_string);  // Reverse the string

    printf("Reversed string: %s\n", input_string);  // Print the reversed string

    int string_length = str_length(input_string);  // Calculate the length of the string
    printf("String length: %d\n", string_length);  // Print the string length

    return 0;
}
