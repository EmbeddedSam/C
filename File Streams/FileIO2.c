/*
 *   File Reading Introduction Program
 *
 *   Sam Walsh
 *   April 24, 2023
 *
 *   This simple C program demonstrates the concept of file reading in C.
 *   It reads the content of a file called "example.txt" and displays it on the screen.
 *   The program uses fopen(), fclose(), and fgets() functions from
 *   the <stdio.h> library to work with file reading.
 *   For more information on file reading and related functions in C, visit the following resources:
 *   IBM documentation on fopen(): https://www.ibm.com/docs/en/i/7.4?topic=functions-fopen-open-files 
 *   IBM documentation on fclose(): https://www.ibm.com/docs/en/i/7.4?topic=functions-fclose-close-stream 
 *   IBM documentation on fgets(): https://www.ibm.com/docs/en/i/7.4?topic=functions-fgets-read-string 
 */

#include <stdio.h>

int main() {
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
