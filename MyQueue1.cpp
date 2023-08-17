#include <iostream>

class MyQueue
{
private:
    class Node
    {
    public:
        int data;
        Node* pnext;
        Node(int data)
        {
            this->data = data;
        }
    };
    int size;
    Node* head;
    Node* tail;
public:
    MyQueue()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    bool empty()
    {
        if (head == nullptr)
            return true;
        return false;
    }
    int Size()
    {
        return this->size;
    }
    int front()
    {
        return head->data;
    }
    int back()
    {
        return tail->data;
    }
    void push(int val)
    {
        if (size == 0)
        {
            tail = new Node(val);
            head = tail;
            size++;
        }
        else
        {
            tail->pnext = new Node(val);
            tail = tail->pnext;
            size++;
        }
    }

    void pop()
    {
        Node* temp = head->pnext;
        delete head;
        head = temp;
        size--;
    }
    void Print()
    {
        Node* temp = this->head;
        while (temp != nullptr)
        {
            std::cout << temp->data << ' ';
            temp = temp->pnext;
        }
    }
    ~MyQueue()
    {
        while (size)
            this->pop();
    }
};

int main()
{
    MyQueue a;
    std::cout << a.empty() << '\n';
    a.push(5);
    a.push(2);
    a.push(3);
    a.push(7);
    a.push(2);
    a.pop();
    a.Print();
}