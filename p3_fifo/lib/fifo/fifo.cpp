
#include <fifo.h>



Fifo::Fifo()
{
    head = buffer;
    tail = buffer;
    FillLvl = 0;
}

int Fifo::get()
{
    int Item;
    std::lock_guard<std::mutex> lock(mtx_fifo);  // Lock the mutex

    if (is_empty() != true)
    {
        Item = *head;
        FillLvl--;

        if (head == (buffer + FIFO_SIZE - 1))
        {
            head = buffer;
        }
        else
        {
            head++;
        }
    }

    // mtx_fifo.unlock();

    return Item;
}

void Fifo::put(int item)
{
    std::lock_guard<std::mutex> lock(mtx_fifo);  // Lock the mutex

    if (is_full() != true)
    {
        *tail = item;
        FillLvl++;

        if (tail == (buffer + FIFO_SIZE - 1))
        {
            tail = buffer;
        }
        else
        {
            tail++;
        }
    }
    else
    {
        tail = buffer;
        *tail = item;
        tail++;
    }
    // mtx_fifo.unlock();
}

bool Fifo::is_empty()
{
    bool bRet = false;

    std::lock_guard<std::mutex> lock(mtx_fifo);  // Lock the mutex

    if (FillLvl == 0)
    {
        bRet = true;
    }
    
    // mtx_fifo.unlock();

    return bRet;
}

bool Fifo::is_full()
{
    bool bRet = false;

    std::lock_guard<std::mutex> lock(mtx_fifo);  // Lock the mutex

    if (FillLvl == FIFO_SIZE)
    {
        bRet = true;
    }

    // mtx_fifo.unlock();

    return bRet;
}

void Fifo::reset()
{
    head = buffer;
    tail = buffer;
    FillLvl = 0;
}