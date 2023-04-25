/*
 * Different ways you can catch and display error messages: Errno, StdError, Perror, printf
 *
 * This simple C program demonstrates how errno and perror()/stderror()/printf work together to provide
 * detailed error information when working with file I/O operations (or errors in general).
 * 
 * Errno is a global variable that is set by system calls and some library functions
 * in the event of an error to indicate what went wrong. 
 * For more information on errno, see: https://www.ibm.com/docs/en/i/7.4?topic=functions-errno-error-number
 * 
 * Perror() is a function that produces a message on the standard error output, 
 * describing the last error encountered during a call to a system or library function.
 * For more information on perror(), see: https://www.ibm.com/docs/en/i/7.4?topic=functions-perror-print-error-message 
 * 
 * Stderr (standard error) is a pre-defined output stream in C, which is used to
 * output error messages or diagnostics. It is usually directed to the same output
 * destination as stdout (standard output), typically the terminal or console.
 * When an error occurs, it is a common practice to write the error messages to
 * stderr instead of stdout. This separation of output streams allows for better
 * handling of program output and error messages. In the example below we redirect it to stdout using printf()
 * For more information on stderr, see: https://www.ibm.com/docs/en/i/7.4?topic=functions-stderr-standard-error-stream 
 * 
 * In this example, if the file does not exist, the errno value will likely be set to:
 * 2 (ENOENT) - No such file or directory
 * 
 * Expected output for each case:
 * 
 * From perror():   "Error opening file: No such file or directory"
 * From printf():   "Error code: 2"
 * From printf() with stderror(): "Error description: No such file or directory"
 * 
 * NOTE: No indidvidual method is better than any other. It is up to YOU as a programmer to
 * decide whether to use system error codes or to make your own error codes.
 */

#include <stdio.h>
#include <errno.h>  // Include the errno header for error handling
#include <string.h> // Include the string header for strerror()

int main() {
    // Try to open a non-existent file
    const char *filename = "non_existent_file.txt";
    FILE *file = fopen(filename, "r");

    // If the file could not be opened
    if (file == NULL) {
        // Use perror to display a descriptive error message
        perror("Error opening file");

        // Use errno to display the specific error code
        printf("Error code: %d\n", errno);

        // Use strerror to display a description of the specific error code
        printf("Error description: %s\n", strerror(errno));
    } else {
        // Close the file if it was opened successfully
        fclose(file);
    }

    return 0;
}