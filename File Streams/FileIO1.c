/*
*	File Writing Introduction Program
*
*   Sam Walsh
*	April 24, 2023
*
*	This simple C program demonstrates the concept of file writing in C.
*	It creates a file called "example.txt" and writes some text to the file.
*	The program uses fopen(), fclose(), and fprintf() functions from
*	the <stdio.h> library to work with file writing.
*	For more information on file writing and related functions in C, visit the following resources:
*   IBM documentation on fopen(): https://www.ibm.com/docs/en/i/7.4?topic=functions-fopen-open-files 
*   IBM documentation on fclose(): https://www.ibm.com/docs/en/i/7.4?topic=functions-fclose-close-stream  
*	IBM documentation on fprintf(): https://www.ibm.com/docs/en/i/7.4?topic=functions-fprintf-write-formatted-data-stream 
*/

#include <stdio.h>
    int main() {
    
    // Declare and initialise a file stream pointer for writing
    FILE *write_stream = fopen("example.txt", "w");

    /* A write stream file pointer is a special kind of variable in the C programming language 
    that helps you interact with a file. It holds the necessary information to manage a file, 
    like its location and how it should be accessed (in this case, for writing).
    When you open a file using the fopen() function, it returns a pointer to a FILE structure. 
    This pointer is called a file stream or file pointer. In our example, write_stream is a file pointer 
    that points to a FILE structure, which represents the "example.txt" file that we want to write to. 
    By using write_stream, we can perform various file operations, like writing data to the file, with the help of other functions provided by the C standard library*/

    // Check if the file opened successfully
    if (write_stream == NULL) {
        printf("Error: Cannot open file for writing.\n");
        return 1;
    }

    // Write some text to the file
    fprintf(write_stream, "This is an example of file writing in C.\n");

    // Close the file stream after writing
    fclose(write_stream);

    printf("Text successfully written to the file.\n");

    return 0;
}