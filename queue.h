#include <iostream>

using namespace std;

#define standard_size = 100;
template <typename T>
class Queue
{
private:
    int front{}, rear{}, size{}, capacity{};
    T *array;

public:
    Queue(int size) : array(new T[size]), size(size), front(0), rear(-1), capacity(size);
    Queue() : array(new T[standard_size]), size{}, front{}, rear(-1), capacity{};
    ~Queue()
    {
        delete array[];
    }

    T dequeue()
    {
        if (isEmpty())
        {
            throw runtime_error("The Queue is empty");
        }
        T temp = array[front];
        cout << "Removing" << temp << endl;
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
        cout << "Inserting" << item << endl;
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

    int size()
    {
        return size;
    }

    bool isEmpty()
    {
        return (size == 0) ? true : false;
    }

    bool isfull()
    {
        return (size == capacity) ? true : false;
    }
};