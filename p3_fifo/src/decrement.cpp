#include <unistd.h>
#include <thread>
#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <mutex>
#include "fifo.h"
#include "decrement.h"

extern std::mutex mtx;// mutex for critical section
extern Fifo CntFifo;

void decrementTask()
{
    
    while (1)
    {
        int val = 0;
        /* Delay for 7 seconds. */
        std::this_thread::sleep_for(std::chrono::milliseconds(7000)); // 7000ms sleep
        /* Wait for the mutex to become available. */
        {
            std::lock_guard<std::mutex> lock(mtx);

            if(CntFifo.is_empty() != true)
            {
                val = CntFifo.get();
                std::cout << "Decrement Task: got var "<< val << std::endl;
            }
            else
            {
                std::cout << "Decrement Task: Fifo is empty!" << std::endl;
            }
        }
        /* Release the mutex. */
        // mtx.unlock();
    }
}
