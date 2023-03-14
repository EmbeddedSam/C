/*
 * Pointer-based Dynamic Memory Allocation Program
 *
 * Sam Walsh 
 * March 14, 2023
 * 
 * This program demonstrates the power of pointers in C by using dynamic memory
 * allocation to create and manipulate an array of integers. The program prompts
 * the user for the size of the array and the integers to be stored in it. Then,
 * it calculates the sum of all the elements in the array using a custom function
 * called 'array_sum'.
 *
 * The 'array_sum' function receives a pointer to the first element of the
 * dynamically allocated array and the number of elements in the array. Using a
 * loop, the function adds each element to the sum and returns the result.
 *
 * The program showcases how pointers can be used for dynamic memory allocation
 * and deallocation, allowing efficient memory management and flexible data
 * structures in C.
 */

#include <stdio.h>
#include <stdlib.h>

int array_sum(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *numbers = (int *)malloc(size * sizeof(int));

    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }

    int total_sum = array_sum(numbers, size);

    printf("The sum of the array elements is: %d\n", total_sum);

    free(numbers);

    return 0;
}
