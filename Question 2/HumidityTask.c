#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include <stdlib.h>

volatile float humidity = 0.0; // Global variable for humidity

void vHumidityTask(void* pvParameters) {
    while (1) {
        // Simulating a sensor reading
        humidity = 50.0f + (float)(rand() % 100) / 10.0f;
        // Generates random values between 50.0% and 60.0%

        // Print the humidity
        printf("Humidity Updated: %.2f%%\n", humidity);

        // Delay for 7 seconds (7000 ms)
        vTaskDelay(pdMS_TO_TICKS(7000));
    }
}
