#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Queue
{
private:
    int front, rear, size, capacity;
    T *array;

public:
    Queue(int size) : array(new T[size]), size(0), front(0), rear(-1), capacity(size) {}
    ~Queue()
    {
        delete[] array;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            throw runtime_error("The Queue is empty");
        }
        T temp = array[front];
        front = (front + 1) % capacity;
        size--;
        return temp;
    }

    void enqueue(T item)
    {
        if (isFull())
        {
            throw runtime_error("Overflow");
        }
        rear = (rear + 1) % capacity;
        array[rear] = item;
        size++;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << array[(front + i) % capacity] << " ";
        }
        cout << endl;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }
    
};

