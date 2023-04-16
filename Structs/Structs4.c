/*
 * Points and Distance Calculation Using Structs and Pointers
 *
 * Sam Walsh
 * April 16, 2023
 *
 * This C program demonstrates the use of structs and pointers to represent points
 * in a 2D coordinate system. The programme calculates the distance between two points
 * using a function that takes pointers to the Point structs.
 * 
 * In this example, we use a Point struct to represent points in a 2D coordinate system. 
 * We have a function calculate_distance that takes pointers to two Point structs 
 * and calculates the distance between them using the Pythagorean theorem. 
 * We pass pointers to the function because it allows the function to efficiently access the original data 
 * without making a copy of the structs. 
 * Also, using const with the pointers ensures that the function won't modify the original data.
 */

#include <stdio.h>
#include <math.h>

// Define Point struct using typedef name
typedef struct {
    double x;
    double y;
} Point;

// Function prototypes
double calculate_distance(const Point *p1, const Point *p2);

int main() {
    // Initialise two Point structs
    Point pointA = {3, 4};
    Point pointB = {6, 8};

    // Calculate the distance between pointA and pointB
    double distance = calculate_distance(&pointA, &pointB);

    // Print the distance
    printf("The distance between pointA(%.2f, %.2f) and pointB(%.2f, %.2f) is %.2f\n", pointA.x, pointA.y, pointB.x, pointB.y, distance);

    return 0;
}

/**
 * Function Name: calculate_distance
 * Function Brief: Calculates the distance between two points in a 2D coordinate system
 *
 * This function takes pointers to two Point structs as input and calculates the distance
 * between them using the Pythagorean theorem. The function efficiently accesses the original
 * data without making a copy of the structs by using pointers.
 *
 * Function Parameters:
 *  (1) p1 The first Point struct (as a const pointer) to calculate the distance from
 *  (2) p2 The second Point struct (as a const pointer) to calculate the distance to
 *
 * Example usage:
 *
 *     Point pointA = {3, 4};
 *     Point pointB = {6, 8};
 *     double distance = calculate_distance(&pointA, &pointB);
 */
double calculate_distance(const Point *p1, const Point *p2) {
    // Calculate the difference in x and y coordinates
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;

    // Use the Pythagorean theorem to calculate the distance
    return sqrt(dx * dx + dy * dy);
}


