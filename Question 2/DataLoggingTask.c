#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include <time.h>

extern volatile float temperature;
extern volatile float humidity;

void vDataLoggingTask(void* pvParameters) {
    FILE* logFile;
    errno_t err;
    err = fopen_s(&logFile, "weather_log.txt", "a");
    if (err != 0) {
        printf("Error opening log file\n");
        return;
    }
    // Open the log file for appending

    if (logFile == NULL) {
        printf("Error opening log file\n");
        return; // Exit if the file cannot be opened
    }

    while (1) {
        time_t currentTime;
        time(&currentTime); // Get the current time

        // Log the temperature and humidity with a timestamp
        char timeBuffer[26];
        ctime_s(timeBuffer, sizeof(timeBuffer), &currentTime);
        fprintf(logFile, "Time: %s - Temperature: %.2f°C, Humidity: %.2f%%\n",
            timeBuffer, temperature, humidity);


        // Flush the file buffer to ensure the data is written immediately
        fflush(logFile);

        // Delay for 10 seconds (10000 ms)
        vTaskDelay(pdMS_TO_TICKS(10000));
    }

    fclose(logFile); // Close the file (though this won't be reached unless task is deleted)
}
