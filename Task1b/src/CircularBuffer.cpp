#include "../include/CircularBuffer.hpp"

namespace cb
{
    template <typename T>
    CircularBuffer<T>::CircularBuffer()
        : buffer{nullptr}, capacity{0}, size{0}, end{0}, start{0}
    {
    }

    template <typename T>
    CircularBuffer<T>::~CircularBuffer()
    {
        delete[] this->buffer;
    }

    template <typename T>
    CircularBuffer<T>::CircularBuffer(const CircularBuffer<T> &cb)
        : capacity{cb.capacity},
          size{cb.size},
          end{cb.end},
          start{cb.start},
          buffer{new T[cb.capacity]}
    {
        for (size_t i = 0; i < capacity; i++)
        {
            buffer[i] = cb.buffer[i];
        }
    }

    template <typename T>
    CircularBuffer<T>::CircularBuffer(int capacity)
        : size{0}, end{0}, start{0}
    {
        set_capacity(capacity);
        this->buffer = new T[this->capacity];
    }

    template <typename T>
    CircularBuffer<T>::CircularBuffer(int capacity, const T &elem)
    {
        set_capacity(capacity);
        size = this->capacity;
        start = 0;
        end = 0;

        buffer = new T[this->capacity];
        for (size_t i = 0; i < this->capacity; i++)
        {
            buffer[i] = elem;
        }
    }

    template <typename T>
    bool CircularBuffer<T>::is_capacity_correct(int capacity) const
    {
        if (new_capacity <= 0)
            throw std::invalid_argument{"Capacity must be greater than 0"};
        capacity = static_cast<size_t>(new_capacity);
    }

}