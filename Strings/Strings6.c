/*
 * String length calculator and reverser using pointers and character arrays (using getchar() input)
 *
 * Sam Walsh 
 * March 21, 2023
 *
 * This simple C program demonstrates basic string manipulation using pointers, char arrays,
 * and the getchar() function to read strings from the user.
 * It takes a string input from the user, reverses it, and prints the original and reversed strings.
 * It also calculates the length of the string.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 256  // Define the maximum string length

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
    char input_string[MAX_LENGTH];  // Declare the char array
    int i = 0;

    printf("Enter a string (max %d characters):\n", MAX_LENGTH - 1);
    // Read the input string using getchar()
    int c;
    while ((c = getchar()) != '\n' && i < MAX_LENGTH - 1) {
        input_string[i++] = (char)c;
    }
    input_string[i] = '\0';  // Add the null terminator at the end of the string

    printf("Original string: %s\n", input_string);  // Print the original string using printf and %s

    reverse_string(input_string);  // Reverse the string

    printf("Reversed string: %s\n", input_string);  // Print the reversed string using printf and %s

    int string_length = str_length(input_string);  // Calculate the length of the string
    printf("String length: %d\n", string_length);  // Print the string length

    return 0;
}
