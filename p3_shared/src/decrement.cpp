#include <unistd.h>
#include <thread>
#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <mutex>

#include "decrement.h"

extern std::mutex mtx;// mutex for critical section
extern int32_t gSharedVariable;

void decrementTask()
{
    while (1)
    {
        /* Delay for 7 seconds. */
        sleep(7);
        /* Wait for the mutex to become available. */
        mtx.lock();

        gSharedVariable--;
        std::cout << "Decrement Task: shared var is "<< gSharedVariable << std::endl;

        /* Release the mutex. */
        mtx.unlock();
    }
}
