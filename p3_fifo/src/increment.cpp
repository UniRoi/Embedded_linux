#include <unistd.h>
#include <thread>
#include <iostream>
#include <mutex>
#include "fifo.h"
#include <stdio.h>
#include <stdint.h>
#include "increment.h"

extern std::mutex mtx;// mutex for critical section
extern Fifo CntFifo;

void incrementTask()
{
    static int cnt = 0;
    while (1)
    {
        /* Delay for 3 seconds. */
        // sleep(3);
        std::this_thread::sleep_for(std::chrono::milliseconds(3000)); // 3000ms sleep
        // std::cout << "inc Task" << std::endl;

        /* Wait for the mutex to become available. */
        {
            std::lock_guard<std::mutex> lock(mtx);

            cnt++;
            if(CntFifo.is_full() != true)
            {
                CntFifo.put(cnt);
                std::cout << "Increment Task: put var " << cnt << std::endl;
            }
            else
            {
                std::cout << "Increment Task: Fifo is full!" << std::endl;
            }
        }
        /* Release the mutex for other task to use. */
        // mtx.unlock();
    }
}
