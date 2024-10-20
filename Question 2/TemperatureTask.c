#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include <stdlib.h>

volatile float temperature = 0.0; // Global variable for temperature

void vTemperatureTask(void* pvParameters) {
    while (1) {
        // Simulating a sensor reading
        temperature = 20.0f + (float)(rand() % 100) / 10.0f;
       // Generates random values between 20.0 and 30.0

        // Print the temperature
        printf("Temperature Updated: %.2f°C\n", temperature);

        // Delay for 5 seconds (5000 ms)
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}
