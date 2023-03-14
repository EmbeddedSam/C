/*
 * String Length Program
 *
 * Sam Walsh 
 * March 14, 2023
 * 
 * This program demonstrates another benefit of pointers in C by calculating
 * the length of a string without using any built-in functions. The program
 * defines a character string and calculates its length using a custom function
 * called 'string_length'.
 *
 * The 'string_length' function receives a pointer to the first character of the
 * string. Using a loop, the function iterates through the string by incrementing
 * the pointer until it reaches the null terminator ('\0'). The function keeps
 * track of the number of iterations, which corresponds to the length of the
 * string, and returns it as the result.
 *
 * After the 'string_length' function call, the program prints the length of
 * the string, illustrating the power of pointer arithmetic in traversing and
 * working with character arrays (strings) in C.
 */

#include <stdio.h>

int string_length(const char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int main() {
    char my_string[] = "Hello, EEE students!";

    int len = string_length(my_string);

    printf("The length of the string is: %d\n", len);

    return 0;
}
