/*
 * Structs, Functions and Pointers Example
 *
 * Sam Walsh
 * April 16, 2023
 *
 * This C program demonstrates the usage of structs and functions
 * to manipulate electric car information. The program initialises
 * variables of the ElectricCar struct type for two different car models
 * (Tesla and Rivian), then uses functions to update, print, and compare car information.
 */

#include <stdio.h>
#include <string.h>

// Define ElectricCar struct using typedef name
typedef struct {
    char brand[50];
    int year;
    double price;
    double battery_capacity;
} ElectricCar;

// Function prototypes
void update_car_price(ElectricCar *car, double new_price);
void print_car_info(ElectricCar car);
void compare_car_prices(ElectricCar car1, ElectricCar car2);

int main() {
    // Initialise two ElectricCar variables (Tesla and Rivian)
    ElectricCar myTesla = {"Tesla Model S", 2022, 80000, 100};
    ElectricCar myRivian = {"Rivian R1T", 2022, 70000, 90};

    // Print car information
    printf("Tesla Car Information:\n");
    print_car_info(myTesla);
    printf("\nRivian Car Information:\n");
    print_car_info(myRivian);

    // Update car prices
    update_car_price(&myTesla, 79000);
    update_car_price(&myRivian, 69000);

    // Print updated car information
    printf("\nUpdated Tesla Car Information:\n");
    print_car_info(myTesla);
    printf("\nUpdated Rivian Car Information:\n");
    print_car_info(myRivian);

    // Compare car prices
    compare_car_prices(myTesla, myRivian);

    return 0;
}

/**
* Function Name: update_car_price
* 
* Function Brief: Updates the price of an ElectricCar struct
* 
* This function takes a pointer to an ElectricCar struct and a new price as inputs.
* It updates the price of the ElectricCar with the new price. The function uses
* a pointer to directly modify the original data, rather than a copy of the struct.
* 
* Function Parameters:
* (1) car A pointer to the ElectricCar struct to be updated
* (2) new_price The new price to set for the ElectricCar
*
* Example usage:
*
* ElectricCar myCar = {"Tesla Model S", 2022, 80000, 100};
*/
void update_car_price(ElectricCar *car, double new_price) {
    car->price = new_price;

// Note for students - In the update_car_price function, we use a pointer to the ElectricCar struct 
// because we want to modify the original car data rather than a copy of it. 
// When you pass a struct to a function, C makes a copy of the struct, so any changes made to the copy inside the function won't affect the original data. 
// By using a pointer, we're passing the memory address of the original struct,  allowing the function to directly modify the original data.
// The -> notation is used to access the members of a struct through a pointer. 
// When you have a pointer to a struct, you can't use the . notation to access its members directly because the pointer holds the memory address of the struct, not the struct itself. 
// The -> operator is a shorthand for dereferencing the pointer and then accessing the member.
}

/**
 * Function Name: print_car_info
 * Function Brief: Prints the information of an ElectricCar struct
 *
 * This function takes an ElectricCar struct as an input and prints its information,
 * including brand, year, price, and battery capacity. The function uses printf()
 * to display the information in a formatted and human-readable way.
 *
 * Function Prameters: 
 *  (1) car The ElectricCar struct to print the information of
 *
 * Example usage:
 *
 *     ElectricCar myCar = {"Tesla Model S", 2022, 80000, 100};
 *     print_car_info(myCar);
 */
void print_car_info(ElectricCar car) {
    printf("Car Brand: %s\n", car.brand);
    printf("Car Year: %d\n", car.year);
    printf("Car Price: £%.2f\n", car.price);
    printf("Battery Capacity: %.2f kWh\n", car.battery_capacity);
}

/**
 * Function Name: compare_car_prices
 * Function Brief: Compares the prices of two ElectricCar structs and prints the result
 *
 * This function takes two ElectricCar structs as input and compares their prices.
 * It then prints a message indicating which car is cheaper, or if they have the
 * same price. The function uses printf() to display the comparison result in a
 * human-readable way.
 *
 * Function Parameters:
 *  (1) car1 The first ElectricCar struct to compare
 *  (2) car2 The second ElectricCar struct to compare
 *
 * Example usage:
 *
 *     ElectricCar car1 = {"Tesla Model S", 2022, 80000, 100};
 *     ElectricCar car2 = {"Rivian R1T", 2022, 70000, 105};
 *     compare_car_prices(car1, car2);
 */
void compare_car_prices(ElectricCar car1, ElectricCar car2) {
    printf("\nComparing Car Prices:\n");
    if (car1.price < car2.price) {
        printf("%s is cheaper than %s\n", car1.brand, car2.brand);
    } else if (car1.price > car2.price) {
        printf("%s is cheaper than %s\n", car2.brand, car1.brand);
    } else {
        printf("%s and %s have the same price\n", car1.brand, car2.brand);
    }
}
