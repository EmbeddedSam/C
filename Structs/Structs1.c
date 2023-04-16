/*
* Struct Introduction Program
* 
* Sam Walsh
* April 16, 2023
* 
* This simple C program demonstrates how to use structs in C to group related data together.
* It defines a struct called "Student" to store information about a student, including their ID,
* name, and age. The program then initialises a Student variable, displays its contents, and
* updates the age of the student.
* For more information on structs in C, visit this tutorial:
* https://www.tutorialspoint.com/cprogramming/c_structures.htm
* https://www.ibm.com/docs/en/rdfi/9.6.0?topic=types-structures-unions 
*/

#include <stdio.h>
#include <string.h>

// Define the Student struct (without a tag)
typedef struct {
int id;
char name[50];
int age;
} Student;

int main() {
    // Declare and initialise a Student variable
    Student student1 = {1824, "Joseph Whitworth", 19};

    // Print the student's information
    printf("Student ID: %d\n", student1.id);
    printf("Student Name: %s\n", student1.name);
    printf("Student Age: %d\n", student1.age);

    // Update the age of the student
    student1.age = 20;
    printf("Student Age (updated): %d\n", student1.age);

    // Declare another student and copy student1 to student2
    Student student2;
    student2.id = student1.id; // note that you can copy struct members directly. 
    strcpy(student2.name, student1.name);
    student2.age = student1.age;

    // Print the copied student's information
    printf("\nCopied Student ID: %d\n", student2.id);
    printf("Copied Student Name: %s\n", student2.name);
    printf("Copied Student Age: %d\n", student2.age);

    return 0;
}


