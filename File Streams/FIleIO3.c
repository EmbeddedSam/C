/*
 *   File Writing and Reading Introduction Program
 *
 *   Sam Walsh
 *   April 24, 2023
 *
 *   This simple C program demonstrates the concepts of both file writing and reading in C.
 *   It first creates a file called "example.txt" and writes some text to the file,
 *   then reads the content of the file and displays it on the screen.
 *   The program uses fopen(), fclose(), fprintf(), and fgets() functions from
 *   the <stdio.h> library to work with file writing and reading.
 *   For more information on file writing and reading and related functions in C, visit the following resources:
 *   IBM documentation on fopen(): https://www.ibm.com/docs/en/i/7.4?topic=functions-fopen-open-files 
 *   IBM documentation on fclose(): https://www.ibm.com/docs/en/i/7.4?topic=functions-fclose-close-stream 
 *   IBM documentation on fprintf(): https://www.ibm.com/docs/en/i/7.4?topic=functions-fprintf-write-formatted-data-stream
 *   IBM documentation on fgets(): https://www.ibm.com/docs/en/i/7.4?topic=functions-fgets-read-string 
 */

#include <stdio.h>

int main() {
    // Declare and initialise a file stream pointer for writing
    FILE *write_stream = fopen("example.txt", "w");

    // Check if the file opened successfully
    if (write_stream == NULL) {
        printf("Error: Cannot open file for writing.\n");
        return 1;
    }

    // Write some text to the file
    fprintf(write_stream, "This is an example of file writing and reading in C.\n");

    // Close the file stream after writing
    fclose(write_stream);

    // Declare and initialise a file stream pointer for reading
    FILE *read_stream = fopen("example.txt", "r");

    // Check if the file opened successfully
    if (read_stream == NULL) {
        printf("Error: Cannot open file for reading.\n");
        return 1;
    }

    // Declare a buffer to store the file content
    char buffer[256];

    // Read the content of the file line by line
    while (fgets(buffer, sizeof(buffer), read_stream) != NULL) {
        // Display the content on the screen
        printf("%s", buffer);
    }

    // Close the file stream after reading
    fclose(read_stream);

    return 0;
}
