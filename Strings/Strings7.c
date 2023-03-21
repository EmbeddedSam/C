/*
 * Mutable and Immutable Pointer Examples (ie. why do we sometimes use const char*?)
 *
 * Sam Walsh 
 * March 21, 2023
 *
 * This C program demonstrates the use of mutable and immutable pointers to mutable and immutable characters/strings.
 * It covers the following 4 cases:
 *   1. char* is a mutable pointer to a mutable character/string.
 *   2. const char* is a mutable pointer to an immutable character/string.
 *   3. char* const is an immutable pointer to a mutable character/string.
 *   4. const char* const is an immutable pointer to an immutable character/string.
 */

#include <stdio.h>

int main() {
    // Example 1: Mutable pointer to a mutable character/string (char*)
    char mutable_string[] = "Mutable string";
    char* mutable_ptr = mutable_string;

    printf("Example 1:\n");
    printf("Before modification: %s\n", mutable_ptr);
    mutable_ptr[0] = 'M'; // Modifying the string through the pointer is allowed
    printf("After modification: %s\n\n", mutable_ptr);

    // Example 2: Mutable pointer to an immutable character/string (const char*)
    const char* immutable_string_ptr = "Immutable string";
    printf("Example 2:\n");
    // immutable_string_ptr[0] = 'I'; // This would cause a compilation error
    printf("Immutable string: %s\n\n", immutable_string_ptr);

    // Example 3: Immutable pointer to a mutable character/string (char* const)
    char another_mutable_string[] = "Another mutable string";
    char* const immutable_ptr = another_mutable_string;

    printf("Example 3:\n");
    printf("Before modification: %s\n", immutable_ptr);
    immutable_ptr[0] = 'A'; // Modifying the string through the pointer is allowed
    printf("After modification: %s\n\n", immutable_ptr);
    // immutable_ptr = mutable_string; // This would cause a compilation error

    // Example 4: Immutable pointer to an immutable character/string (const char* const)
    const char* const immutable_string_and_ptr = "Fully immutable string";
    printf("Example 4:\n");
    // immutable_string_and_ptr[0] = 'F'; // This would cause a compilation error
    // immutable_string_and_ptr = mutable_string; // This would cause a compilation error
    printf("Fully immutable string: %s\n", immutable_string_and_ptr);

    return 0;
}
