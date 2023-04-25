/*
*	Electronic Component Data Processing using fgets() sscanf() and rewind()
*
*	Sam Walsh
*	April 24, 2023
*
*	This C program demonstrates reading and processing electronic component data from a file.
*	It first writes the data of electrical components to a file named "components.txt"
*	and then reads and processes each line of the file to print the resistance values of the components.
*	The program uses fgets() to read whole lines and sscanf() to process the lines.
*	sscanf() is chosen because it allows for flexible and efficient parsing of the lines with various data types.
*	The rewind() function is used to reset the file position indicator to the beginning of the file.
*/

#include <stdio.h>

/*
* Function name: write_data_to_file
* ----------------------------
* Brief: Writes the electronic component data to the given file.
*
* Parameters: file: A FILE pointer to the file where the data will be written.
*
* returns: 0 if the data was written successfully, 1 if there was an error.
*
* Example usage:
*   FILE *file = fopen("components.txt", "w");
*   int status = write_data_to_file(file);
*   fclose(file);
*/
int write_data_to_file(FILE *file) {
    if (file == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    fprintf(file, "Resistor1,1000,0,0\n");
    fprintf(file, "Capacitor1,0,10e-6,0\n");
    fprintf(file, "Inductor1,0,0,0.01\n");

    return 0;
}


int main() {
    // Open the file "components.txt" for writing
    FILE *file = fopen("components.txt", "w+");
    /*
        The "w+" file mode is used to open a file for both reading and writing. When using "w+", the file is either created if it doesn't exist or truncated (i.e., its size is reduced to zero) if it does exist. The file pointer is positioned at the beginning of the file.

        Here's a summary of the most common file modes in C:
        "r": Open a file for reading. The file must exist.
        "w": Open a file for writing. If the file doesn't exist, it will be created. If the file exists, its contents will be truncated.
        "a": Open a file for appending. If the file doesn't exist, it will be created. If the file exists, the file pointer is positioned at the end of the file, so new data will be added to the end.
        "r+": Open a file for reading and writing. The file must exist.
        "w+": Open a file for reading and writing. If the file doesn't exist, it will be created. If the file exists, its contents will be truncated.
        "a+": Open a file for reading and appending. If the file doesn't exist, it will be created. If the file exists, the file pointer is positioned at the end of the file for writing, but you can move the file pointer anywhere in the file for reading.
    */
    if (file == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    // Write the electronic component data to the file
    int status_code = write_data_to_file(file);
    if (status_code != 0) {
        fclose(file);
        return status_code;
    }

    // Rewind the file position indicator to the beginning of the file
    rewind(file);

    // Read and process each line of the file
    char line[50];
    char component_name[50];
    float resistance, capacitance, inductance;
    printf("Resistance values of electrical components:\n");

    while (fgets(line, sizeof(line), file) != NULL) {
        // Process the line using sscanf()
        // sscanf() is chosen because it allows for flexible and efficient parsing of the lines with various data types
        // The format string "%[^,],%f,%f,%f" tells sscanf() to parse:
        // 1. A string of characters up to the first comma into component_name
        // 2. A floating-point number into resistance
        // 3. A floating-point number into capacitance
        // 4. A floating-point number into inductance
        if (sscanf(line, "%[^,],%f,%f,%f", component_name, &resistance, &capacitance, &inductance) == 4) {
            // Print the resistance value of the current component
            printf("%s: %.2f Ohms\n", component_name, resistance);
        } else {
            printf("Error processing line: %s", line);
            fclose(file);
            return 1;
        }
    }

    // Close the file
    fclose(file);
    return 0;
}
