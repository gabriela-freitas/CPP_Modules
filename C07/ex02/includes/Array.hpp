#pragma once

/*
Develop a class template Array that contains elements of type T and that implements
the following behavior and functions:
*/

template <typename T>
class Array
{
    public:
    // Construction with no parameter: Creates an empty array.
    Array()
    {
        _array = new T;
        _size = 0;
    }

    // Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default.
    //      Tip: Try to compile int * a = new int(); then display *a.
    Array(unsigned int n)
    {
        _array = new T[n];
        _size = n;
    }

    // Construction by copy and assignment operator. In both cases, modifying either the
    // original array or its copy after copying musn’t affect the other array.
    Array(Array &other)
    {
        _array = new T[other.size()];
        _size = other.size();
        for (unsigned int i = 0; i < _size; i++)
        {
            _array[i] = other[i];
        }
    }

    Array& operator=(Array &other)
    {
        delete[] _array;
        _array = new T[other.size()];
        _size = other.size();
        for (unsigned int i = 0; i < _size; i++)
        {
            _array[i] = other[i];
        }
    }

    ~Array()
    {
        std::cout << "cleaning memory" << std::endl;
        delete[] _array;
    }

    // A member function size() that returns the number of elements in the array. This
    // member function takes no parameter and musn’t modify the current instance.
    unsigned int size() const
    {
        return _size;
    }

    // Elements can be accessed through the subscript operator: [ ].
    // When accessing an element with the [ ] operator, if its index is out of bounds, an
    // std::exception is thrown.
    T& operator[](int index) {
        if (index < 0 || index >= (int)_size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _array[index];
    }

    private:
        T *_array;
        unsigned int _size;
};