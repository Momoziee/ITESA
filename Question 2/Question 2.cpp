#include "FreeRTOS.h"
#include "task.h"
#include "Tasks.h"
#include <stdio.h>
#include "DisplayTask.c"
#include "TemperatureTask.c"
#include "DataLoggingTask.c"
#include "HumidityTask.c"


// Function prototypes for tasks
void vTemperatureTask(void* pvParameters);
void vHumidityTask(void* pvParameters);
void vDataLoggingTask(void* pvParameters);
void vDisplayTask(void* pvParameters);

int main(void) {
    // Create the temperature monitoring task
    xTaskCreate(vTemperatureTask, "Temperature Task", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    // Create the humidity monitoring task
    xTaskCreate(vHumidityTask, "Humidity Task", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    // Create the data logging task
    xTaskCreate(vDataLoggingTask, "Logging Task", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    // Create the display task
    xTaskCreate(vDisplayTask, "Display Task", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    // Start the FreeRTOS scheduler
    vTaskStartScheduler();

    // If the scheduler exits (which it shouldn't), halt the program
    for (;;);

}
void vApplicationStackOverflowHook(TaskHandle_t xTask, char* pcTaskName) {
    // Handle the stack overflow here
    printf("Stack overflow detected in task: %s\n", pcTaskName);
    while (1); // Halt the system or reset
}

void vApplicationTickHook(void) {
    // This function is called every tick interrupt, can be left empty if unused
}

void vApplicationGetIdleTaskMemory(StaticTask_t** ppxIdleTaskTCBBuffer,
    StackType_t** ppxIdleTaskStackBuffer,
    uint32_t* pulIdleTaskStackSize) {
    // Implement this only if using statically allocated tasks. Can be left empty if using dynamic allocation
}

