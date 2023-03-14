/*
 * Pointer Swap Program
 *
 * Sam Walsh 
 * March 14, 2023
 * 
 * This program demonstrates the power of pointers in C by swapping the values
 * of two integer variables using a function. The program first initialises two
 * integer variables, x and y, and prints their starting values. It then calls the
 * 'swap' function, passing the addresses of these variables.
 *
 * The 'swap' function receives the addresses of x and y as pointers. By
 * dereferencing the pointers, the function can directly access and modify the
 * original variables. The function swaps the values of x and y using a temporary
 * variable, and the changes are reflected in the main function.
 *
 * After the 'swap' function call, the program prints the updated values of x
 * and y to demonstrate the successful value swap.
 */


#include <stdio.h>

// Function to swap two integers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10;
    int y = 20;

    printf("Before swapping:\n");
    printf("x = %d, y = %d\n", x, y);

    swap(&x, &y);

    printf("After swapping:\n");
    printf("x = %d, y = %d\n", x, y);

    return 0;
}
