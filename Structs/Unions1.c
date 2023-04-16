/*
 * Union Introduction Example
 *
 * Sam Walsh
 * April 16, 2023
 *
 * This simple C program demonstrates the concept of unions in the C language.
 * Unions allow for efficient memory usage as they store different data types
 * in the same memory location. In contrast, structs use separate memory locations
 * for each member. The program initialises a union called 'Data' that can store
 * an integer, a float, or a string. The example illustrates how to access and
 * modify the different data types stored in the union.
 */

#include <stdio.h>
#include <string.h>

// Define a union named 'Data'
typedef union {
    int intValue;
    float floatValue;
    char stringValue[20];
} Data;

int main() {
    // Declare and initialize a Data union
    Data myData;

    // Assign an integer value to the union
    myData.intValue = 42;
    printf("Integer value: %d\n", myData.intValue);

    // Assign a float value to the union
    myData.floatValue = 3.14f;
    printf("Float value: %.2f\n", myData.floatValue);

    // Assign a string value to the union
    strncpy(myData.stringValue, "Hello, world!", sizeof(myData.stringValue) - 1);
    myData.stringValue[sizeof(myData.stringValue) - 1] = '\0';
    printf("String value: %s\n", myData.stringValue);

    return 0;
}
