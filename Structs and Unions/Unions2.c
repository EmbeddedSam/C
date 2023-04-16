/*
 * Struct vs. Union Example
 *
 * Sam Walsh
 * April 16, 2023
 *
 * This C program demonstrates when to use a struct and when to use a union in
 * the context of electronic engineering. The program defines a struct called
 * 'SensorDataPacket' that contains a sensor data type (temperature, pressure,
 * or humidity) and a union that stores the corresponding sensor value. Using
 * a struct allows us to group related data together, while the union enables
 * efficient memory usage by storing different data types in the same memory
 * location.
 */

#include <stdio.h>

// Define a union to store different types of sensor data
typedef union {
    float temperature; // Temperature in degrees Celsius
    float pressure;    // Pressure in Pascals
    int humidity;      // Relative Humidity in percentage
} SensorValue;

// Define a struct to represent a sensor data packet
typedef struct {
    int sensorType;     // 0: Temperature, 1: Pressure, 2: Humidity
    SensorValue value;  // Union to store the sensor value
} SensorDataPacket;

int main() {
    // Initialise a Temperature SensorDataPacket
    SensorDataPacket tempPacket;
    tempPacket.sensorType = 0;
    tempPacket.value.temperature = 25.3f;

    // Initialise a Pressure SensorDataPacket
    SensorDataPacket pressurePacket;
    pressurePacket.sensorType = 1;
    pressurePacket.value.pressure = 100325.0f;

    // Initialise a Humidity SensorDataPacket
    SensorDataPacket humidityPacket;
    humidityPacket.sensorType = 2;
    humidityPacket.value.humidity = 55;

    // Print the SensorDataPackets
    printf("Temperature Packet - Type: %d, Temperature: %.1f °C\n", tempPacket.sensorType, tempPacket.value.temperature);
    printf("Pressure Packet - Type: %d, Pressure: %.1f Pa\n", pressurePacket.sensorType, pressurePacket.value.pressure);
    printf("Humidity Packet - Type: %d, Humidity: %d%%\n", humidityPacket.sensorType, humidityPacket.value.humidity);

    return 0;
}
