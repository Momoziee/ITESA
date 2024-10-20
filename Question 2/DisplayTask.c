#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>

extern volatile float temperature;
extern volatile float humidity;

void vDisplayTask(void* pvParameters) {
    while (1) {
        // Print the current temperature and humidity
        printf("Current Temperature: %.2f°C, Humidity: %.2f%%\n", temperature, humidity);

        // Delay for 2 seconds (2000 ms)
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
