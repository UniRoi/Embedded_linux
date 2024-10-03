#include <iostream>
#include <thread>
#include <stdint.h>
#include <mutex>

#include "decrement.h"
#include "increment.h"

int32_t gSharedVariable = 0;
std::mutex mtx;// mutex for critical section

int main(void)
{
    /* Create the increment and decrement tasks using the default task
    * attributes. Do not pass in any parameters to the tasks. */
    std::thread incrementTaskObj (incrementTask);
    std::thread decrementTaskObj (decrementTask);
    
    /* Allow the tasks to run. */
    incrementTaskObj.join();
    decrementTaskObj.join();
    
    return 0;
}