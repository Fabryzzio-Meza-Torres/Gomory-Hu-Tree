#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Queue
{
private:
    int front, rear, size, capacity;
    T *array;
    int color[MAX_NODES]; // Declarar color aquí para usarlo en dequeue y enqueue

public:
    Queue(int size) : array(new T[size]), size(0), front(0), rear(-1), capacity(size)
    {
        for (int i = 0; i < MAX_NODES; ++i) {
            color[i] = 0; // Inicializar color como White
        }
    }

    ~Queue()
    {
        delete[] array;
    }

    void enqueue(T item, int color[int MAX_NODES])
    {
        if (isFull())
        {
            throw runtime_error("Overflow");
        }
        rear = (rear + 1) % capacity;
        array[rear] = item;
        size++;
        color[item] = GRAY; // Colorear el nodo en gris al encolarlo
    }

    T dequeue(int color[int MAX_NODES])
    {
        if (isEmpty())
        {
            throw runtime_error("The Queue is empty");
        }
        T temp = array[front];
        front = (front + 1) % capacity;
        size--;
        color[temp] = BLACK; // Colorear el nodo en negro al desencolarlo
        return temp;
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