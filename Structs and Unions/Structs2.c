/*
 * Structs and Nested Structs Example
 *
 * Sam Walsh
 * April 16, 2023
 *
 * This C program demonstrates the usage of structs and nested structs to model an electric car,
 * a petrol car, a hybrid car, and a showroom containing one of each type of car.
 * 
 * The program initialises variables of the ElectricCar, PetrolCar, HybridCar,
 * and Showroom struct types, then prints the car information for each car in the showroom.
 *
 * The example uses typedef names instead of struct tags, which is the more
 * common and preferred method in modern C code for better readability.
 */

#include <stdio.h>
#include <string.h>

// Define ElectricCar, PetrolCar, and HybridCar structs using typedef names
typedef struct {
    char brand[50];
    int year;
    double price;
    double battery_capacity;
} ElectricCar;

typedef struct {
    char brand[50];
    int year;
    double price;
    double fuel_capacity;
} PetrolCar;

typedef struct {
    char brand[50];
    int year;
    double price;
    double battery_capacity;
    double fuel_capacity;
} HybridCar;

// Define a Showroom struct containing ElectricCar, PetrolCar, and HybridCar structs
typedef struct {
    ElectricCar electric_car;
    PetrolCar petrol_car;
    HybridCar hybrid_car;
} Showroom;

int main() {
    // Initialise ElectricCar, PetrolCar, and HybridCar variables
    ElectricCar myElectricCar = {"Tesla", 2022, 80000, 100};
    PetrolCar myPetrolCar = {"Ford", 2020, 30000, 12};
    HybridCar myHybridCar = {"Toyota", 2021, 35000, 1.6, 11};

    // Initialise a Showroom struct variable
    Showroom myShowroom = {myElectricCar, myPetrolCar, myHybridCar};

    // Print the showroom's ElectricCar's information
    printf("Showroom Electric Car Brand: %s\n", myShowroom.electric_car.brand);
    printf("Showroom Electric Car Year: %d\n", myShowroom.electric_car.year);
    printf("Showroom Electric Car Price: £%.2f\n", myShowroom.electric_car.price);
    printf("Showroom Electric Car Battery Capacity: %.2f kWh\n", myShowroom.electric_car.battery_capacity);

    // Print the showroom's PetrolCar's information
    printf("\nShowroom Petrol Car Brand: %s\n", myShowroom.petrol_car.brand);
    printf("Showroom Petrol Car Year: %d\n", myShowroom.petrol_car.year);
    printf("Showroom Petrol Car Price: £%.2f\n", myShowroom.petrol_car.price);
    printf("Showroom Petrol Car Fuel Capacity: %.2f litres\n", myShowroom.petrol_car.fuel_capacity);

    // Print the showroom's HybridCar's information
    printf("\nShowroom Hybrid Car Brand: %s\n", myShowroom.hybrid_car.brand);
    printf("Showroom Hybrid Car Year: %d\n", myShowroom.hybrid_car.year);
    printf("Showroom Hybrid Car Price: £%.2f\n", myShowroom.hybrid_car.price);
    printf("Showroom Hybrid Car Battery Capacity: %.2f kWh\n", myShowroom.hybrid_car.battery_capacity);
    printf("Showroom Hybrid Car Fuel Capacity: %.2f litres\n", myShowroom.hybrid_car.fuel_capacity);

    return 0;
}
