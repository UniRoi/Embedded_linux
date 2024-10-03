#include <unistd.h>
#include <thread>
#include <iostream>
#include <mutex>

#include <stdio.h>
#include <stdint.h>
#include "increment.h"

extern std::mutex mtx;// mutex for critical section
extern int32_t gSharedVariable;

void incrementTask()
{
    while (1)
    {
        /* Delay for 3 seconds. */
        sleep(3);

        /* Wait for the mutex to become available. */
        mtx.lock();

        gSharedVariable++;
        std::cout << "Increment Task: shared var is " << gSharedVariable << std::endl;

        /* Release the mutex for other task to use. */
        mtx.unlock();
    }
}
