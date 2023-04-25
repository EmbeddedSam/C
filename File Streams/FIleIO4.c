/*
*	Binary File I/O Introduction Program
*
*	Sam Walsh
*	April 24, 2023
*
*	This simple C program demonstrates reading and writing to binary files.
*	It defines a struct called Student, writes an array of Student structs to
*	a binary file, and then reads the data back from the binary file.
*	The program uses fopen(), fclose(), fread(), and fwrite() functions from
*	the <stdio.h> library for binary file I/O.
*   When working with binary files, make sure to use the "wb" (write binary) and "rb" (read binary) 
*   modes when opening the files with fopen()
*/

#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    float degree_grade;
} Student;

int main() {
    // Initialise an array of Student structs
    Student students[] = {
        {1, "Alan", 1.0},
        {2, "Ernest", 2.1},
        {3, "Niels", 2.1}
    };
    int num_students = sizeof(students) / sizeof(Student);

    // Write the Student structs to a binary file
    FILE *output_file = fopen("students.bin", "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        return 1;
    }
    fwrite(students, sizeof(Student), num_students, output_file);
    fclose(output_file);

    // Read the Student structs back from the binary file
    FILE *input_file = fopen("students.bin", "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }
    Student read_students[num_students];
    fread(read_students, sizeof(Student), num_students, input_file);
    fclose(input_file);

    // Print the read Student structs
    printf("Read students from binary file:\n");
    for (int i = 0; i < num_students; i++) {
        printf("ID: %d, Name: %s, Degree: %.1f\n", read_students[i].id, read_students[i].name, read_students[i].degree_grade);
    }

    return 0;
}
