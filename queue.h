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
    Queue(int size = 100) : array(new T[size]), size(0), front(0), rear(-1), capacity(size) {}
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
        cout << "Removing " << temp << endl;
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
        cout << "Inserting " << item << endl;
        rear = (rear + 1) % capacity;
        array[rear] = item;
        size++;
    }

    T peek()
    {
        if (isEmpty())
        {
            throw runtime_error("The Queue is empty");
        }
        return array[front];
    }

    int getSize()
    {
        return size;
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

