#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node() : next(nullptr) {}  
    Node(int data)
    {
        data = data;
        next = nullptr;
    }
};

class ForwardList
{
private:
    Node *head;
public:   
    ForwardList() : head(nullptr) {}
    void push_front(int data)
    {
        Node *new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }
    void pop_front()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    int front()
    {
        if (head == nullptr)
        {
            return -1;
        }
        return head->data;
    }
    int operator[](int index)
    {
        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            if (temp == nullptr)
            {
                return -1;
            }
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            return -1;
        }
        return temp->data;
    }
    bool empty()
    {
        return head == nullptr;
    }
    void clear()
    {
        while (head != nullptr)
        {
            pop_front();
        }
    }
    ~ForwardList()
    {
        clear();
    }
};

