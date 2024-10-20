#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#define configUSE_PREEMPTION            1
#define configUSE_IDLE_HOOK             0
#define configCHECK_FOR_STACK_OVERFLOW  0
#define configUSE_TICK_HOOK             0
#define configCPU_CLOCK_HZ              ( ( unsigned long ) 80000000 )    
#define configTICK_RATE_HZ              ( ( TickType_t ) 1000 )   /* 1 ms tick */
#define configMAX_PRIORITIES            ( 5 )
#define configMINIMAL_STACK_SIZE        ( ( unsigned short ) 128 )
#define configTOTAL_HEAP_SIZE           ( ( size_t ) ( 20 * 1024 ) )
#define configMAX_TASK_NAME_LEN         ( 16 )
#define configUSE_TRACE_FACILITY        1
#define configUSE_16_BIT_TICKS          0
#define configIDLE_SHOULD_YIELD         1


#define INCLUDE_vTaskDelay              1
#define INCLUDE_vTaskStartScheduler     1

#endif /* FREERTOS_CONFIG_H */
