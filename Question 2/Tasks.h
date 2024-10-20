#ifndef TASKS_H
#define TASKS_H

void vTemperatureTask(void* pvParameters);
void vHumidityTask(void* pvParameters);
void vDataLoggingTask(void* pvParameters);
void vDisplayTask(void* pvParameters);

#endif /* TASKS_H */
