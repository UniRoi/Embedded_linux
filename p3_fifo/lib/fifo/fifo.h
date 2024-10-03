#ifndef FIFO_H
#define FIFO_H

#include <mutex>


const int FIFO_SIZE = 5;

class Fifo
{
public:
    Fifo();
    int get();
    void put(int item);
    bool is_empty();
    bool is_full();
    void reset();
private:
    int buffer[FIFO_SIZE];
    // Part 2: add a variable for the current element count
    int FillLvl;
    // Part 3: add variables pointing to the front and back of the buffer
    int *head;
    int *tail;
    std::mutex mtx_fifo;
};

#endif // FIFO_H


