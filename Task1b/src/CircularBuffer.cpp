#include "../include/CircularBuffer.hpp"

namespace cb
{
    template <typename T>
    CircularBuffer<T>::CircularBuffer()
        : _buffer{nullptr}, _capacity{0}, _size{0}, _end{0}, _start{0}
    {
    }

    template <typename T>
    CircularBuffer<T>::~CircularBuffer()
    {
        delete[] this->_buffer;
    }

    template <typename T>
    CircularBuffer<T>::CircularBuffer(const CircularBuffer<T> &cb)
        : _capacity{cb._capacity},
          _size{cb._size},
          _end{cb._end},
          _start{cb._start},
          _buffer{new T[cb._capacity]}
    {
        for (size_t i = 0; i < capacity; i++)
        {
            _buffer[i] = cb._buffer[i];
        }
    }

    template <typename T>
    CircularBuffer<T>::CircularBuffer(int capacity)
        : _size{0}, _end{0}, _start{0}
    {
        is_capacity_correct(capacity);
        this->_capacity = static_cast<size_t>(capacity);
        this->_buffer = new T[this->_capacity];
    }

    template <typename T>
    CircularBuffer<T>::CircularBuffer(int capacity, const T &elem)
    {
        is_capacity_correct(capacity);
        this->_capacity = static_cast<size_t>(capacity);
        _size = this->_capacity;
        _start = 0;
        _end = 0;

        _buffer = new T[this->_capacity];
        for (size_t i = 0; i < this->_capacity; i++)
        {
            _buffer[i] = elem;
        }
    }

    template <typename T>
    void CircularBuffer<T>::is_capacity_correct(int capacity) const
    {
        if (capacity <= 0)
            throw std::invalid_argument{"Capacity must be greater than 0"};
    }

}