/*
*	Binary File I/O with Simple Error Handling
*
*	Sam Walsh
*	April 24, 2023
*
*	This C program demonstrates reading and writing to binary files with error handling.
*	It defines a struct called Component, writes an array of Component structs to
*	a binary file, and then reads the data back from the binary file.
*	The program uses fopen(), fclose(), fread(), fwrite(), and perror() functions from
*	the <stdio.h> library for binary file I/O and error handling.
*/

#include <stdio.h>

typedef struct {
    int id;
    char type[50];
    float resistance;
    float capacitance;
    float inductance;
} Component;

int main() {
    // Initialise an array of Component structs
    Component components[] = {
        {1, "Resistor", 1000.0, 0.0, 0.0},
        {2, "Capacitor", 0.0, 0.001, 0.0},
        {3, "Inductor", 0.0, 0.0, 50.0}
    };
    int num_components = sizeof(components) / sizeof(Component);

    // Write the Component structs to a binary file
    FILE *output_file = fopen("components.bin", "wb");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        // perror("Error opening output file"); could also use perror() here
        return 1;
    }

    size_t written_elements = fwrite(components, sizeof(Component), num_components, output_file);
    if (written_elements != num_components) {
        printf("Error writing output file\n");
        //perror("Error writing to output file"); could also use perror() here
        fclose(output_file);
        return 1;
    }

    fclose(output_file);

    // Read the Component structs back from the binary file
    FILE *input_file = fopen("components.bin", "rb");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        //perror("Error opening input file"); // could also use perror() here
        return 1;
    }

    Component read_components[num_components];
    size_t read_elements = fread(read_components, sizeof(Component), num_components, input_file);
    if (read_elements != num_components) {
        printf("Error reading input file\n");
        //perror("Error reading from input file"); // could also use perror() here
        fclose(input_file);
        return 1;
    }

    fclose(input_file);

    // Print the read Component structs
    printf("Read components from binary file:\n");
    for (int i = 0; i < num_components; i++) {
        printf("ID: %d, Type: %s, Resistance: %.2f, Capacitance: %.3f, Inductance: %.3f\n", read_components[i].id, read_components[i].type, read_components[i].resistance, read_components[i].capacitance, read_components[i].inductance);
    }

    return 0;
}
