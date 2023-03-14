/*
 * Pointer Arithmetic Program
 *
 * Sam Walsh 
 * March 14, 2023
 * 
 * This program demonstrates the power of pointers in C by using pointer
 * arithmetic to find the sum of all elements in an array. The program
 * initialises an integer array with five elements and calculates the sum
 * using a function called 'array_sum'.
 *
 * The 'array_sum' function receives a pointer to the first element of the
 * array and the number of elements in the array. Using a loop, the function
 * iterates through the array by incrementing the pointer, and it adds each
 * element to the sum. The function then returns the sum.
 *
 * After the 'array_sum' function call, the program prints the total sum of
 * the array elements, showcasing the benefits of pointer arithmetic in
 * traversing and manipulating arrays.
 */

#include <stdio.h>

int array_sum(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int total_sum = array_sum(numbers, size);

    printf("The sum of array elements is: %d\n", total_sum);

    return 0;
}
