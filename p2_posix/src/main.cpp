#include <pthread.h>
#include <stdint.h>

#include "decrement.h"
#include "increment.h"

pthread_mutex_t sharedVariableMutex;
int32_t gSharedVariable = 0;

/* Declare the task variables. */
pthread_t incrementTaskObj;
pthread_t decrementTaskObj;

int main(void)
{
    /* Create the mutex for accessing the shared variable using the
    * default attributes. */
    pthread_mutex_init(&sharedVariableMutex, NULL);
    /* Create the increment and decrement tasks using the default task
    * attributes. Do not pass in any parameters to the tasks. */
    pthread_create(&incrementTaskObj, NULL, incrementTask, NULL);
    pthread_create(&decrementTaskObj, NULL, decrementTask, NULL);
    /* Allow the tasks to run. */
    pthread_join(incrementTaskObj, NULL);
    pthread_join(decrementTaskObj, NULL);
    
    return 0;
}