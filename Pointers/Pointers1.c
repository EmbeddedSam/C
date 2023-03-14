/*
 * Pointer Introduction Program
 *
 * Sam Walsh 
 * March 14, 2023
 * 
 * This simple program is designed to introduce the concept of pointers.
 * It demonstrates the basics of pointers, including declaring a pointer, 
 * assigning the address of a variable to the pointer, and using the pointer
 * to access and modify the original variable's value.
 *
 * First, we declare an integer variable called 'x' and assign it the
 * value 10. We also declare an integer pointer called 'x_ptr'.
 *
 * Next, we assign the address of the 'x' variable to 'x_ptr' using
 * the '&' (address-of) operator.
 *
 * Then, we use the '*' (dereference) operator to access the value stored at
 * the address pointed to by 'x_ptr' and increase the value by 5.
 *
 * Finally, we print the updated value of 'x' to show that the pointer
 * allowed us to directly access and modify the original variable.
 */

#include <stdio.h>

int main() {
    int x = 10;          // Declare an integer variable called 'x' and assign it the value 10
    int *x_ptr;          // Declare an integer pointer called 'x_ptr'

    x_ptr = &x;     // Assign the address of 'x' to 'x_ptr'

    *x_ptr += 5;         // Add 5 to the value stored at the address pointed to by 'x_ptr'

    printf("Updated value of 'x': %d\n", x); // Print the updated value of 'x'

    return 0;
}
