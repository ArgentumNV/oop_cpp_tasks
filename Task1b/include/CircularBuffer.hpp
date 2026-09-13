#pragma once

namespace cb
{
    // typedef char value_type;
    template <class T>
    class CircularBuffer
    {
        T *buffer;
        /*... реализация ... */
    public:
        CircularBuffer();
        ~CircularBuffer();
        CircularBuffer(const CircularBuffer &cb);

        // Конструирует буфер заданной ёмкости.
        explicit CircularBuffer(int capacity);

        // Конструирует буфер заданной ёмкости, целиком заполняет его элементом elem.
        CircularBuffer(int capacity, const T &elem);

        // Доступ по индексу. Не проверяют правильность индекса.
        T &operator[](int i);
        const T &operator[](int i) const;

        // Доступ по индексу. Методы бросают исключение в случае неверного индекса.
        T &at(int i);
        const T &at(int i) const;

        T &front(); // Ссылка на первый элемент.
        T &back();  // Ссылка на последний элемент.
        const T &front() const;
        const T &back() const;

        // Линеаризация - сдвинуть кольцевой буфер так, что его первый элемент
        // переместится в начало аллоцированной памяти. Возвращает указатель
        // на первый элемент.
        T *linearize();

        // Проверяет, является ли буфер линеаризованным.
        bool is_linearized() const;

        // Сдвигает буфер так, что по нулевому индексу окажется элемент
        // с индексом new_begin.
        void rotate(int new_begin);

        // Количество элементов, хранящихся в буфере.
        int size() const;
        bool empty() const;

        // true, если size() == capacity().
        bool full() const;

        // Количество свободных ячеек в буфере.
        int reserve() const;

        // ёмкость буфера
        int capacity() const;

        void set_capacity(int new_capacity);

        // Изменяет размер буфера.
        // В случае расширения, новые элементы заполняются элементом item.
        void resize(int new_size, const T &item = value_type());

        // Оператор присваивания.
        CircularBuffer &operator=(const CircularBuffer &cb);

        friend bool operator==(const CircularBuffer &a, const CircularBuffer &b);
        friend bool operator!=(const CircularBuffer &a, const CircularBuffer &b);

        // Обменивает содержимое буфера с буфером cb.
        void swap(CircularBuffer &cb);

        // Добавляет элемент в конец буфера.
        // Если текущий размер буфера равен его ёмкости, то переписывается
        // первый элемент буфера (т.е., буфер закольцован).
        void push_back(const T &item = T());
        // Добавляет новый элемент перед первым элементом буфера.
        // Аналогично push_back, может переписать последний элемент буфера.
        void push_front(const T &item = T());
        // удаляет последний элемент буфера.
        void pop_back();
        // удаляет первый элемент буфера.
        void pop_front();

        // Вставляет элемент item по индексу pos. Ёмкость буфера остается неизменной.
        void insert(int pos, const T &item = T());
        // Удаляет элементы из буфера в интервале [first, last).
        void erase(int first, int last);
        // Очищает буфер.
        void clear();
    };

    // bool CircularBuffer::operator==(const CircularBuffer &a, const CircularBuffer &b);
    // bool operator!=(const CircularBuffer &a, const CircularBuffer &b);

}