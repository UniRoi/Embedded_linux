#include <iostream>
#include <thread>
#include <stdint.h>
#include <mutex>
#include "fifo.h"

#include "decrement.h"
#include "increment.h"

std::mutex mtx;// mutex for critical section

Fifo CntFifo;

int main(void)
{
    std::cout << "start fifo example\n";
    CntFifo.reset();
    /* Create the increment and decrement tasks using the default task
    * attributes. Do not pass in any parameters to the tasks. */
    std::thread incrementTaskObj (incrementTask);
    std::thread decrementTaskObj (decrementTask);
    
    /* Allow the tasks to run. */
    incrementTaskObj.join();
    decrementTaskObj.join();
    
    return 0;
}