#include <iostream>
template<typename T>
class MyList
{
private:

    struct Node
    {
        T data;
        Node* pnext = nullptr;
        Node(T data)
        {
            this->data = data;
        }
    };

    Node* head = nullptr;

    int size = 0;

public:

    void push_front(T data)
    {
        size++;
        Node* temp = head;
        head = new Node(data);
        head->pnext = temp;
    }

    void push_back(T data)
    {
        if (head == nullptr)
        {
            this->push_front(data);
            return;
        }
        Node* current = head;
        while (current->pnext != nullptr)
        {
            current = current->pnext;
        }
        current->pnext = new Node(data);
        size++;
    }

    void insert(T data, int index)
    {
        Node* current = head;
        if (index >= size)
            throw std::exception("no such index");
        for (int i = 0; i < index - 1; i++)
        {
            current = current->pnext;
        }
        Node* temp = current->pnext;
        current->pnext = new Node(data);
        current->pnext->pnext = temp;
        size++;
    }

    void pop_front()
    {
        if (head == nullptr)
            throw std::exception("nothing to delete");
        Node* temp = head;
        head = head->pnext;
        delete temp;
        size--;
    }

    void pop_back(T data)
    {
        Node* current = head;
        while (current->pnext != nullptr)
        {
            current = current->pnext;
        }
        delete current;
        size--;
    }

    void erase(int index)
    {
        Node* current = head;
        if (index >= size)
            throw std::exception("no such index");
        for (int i = 0; i < index - 1; i++)
        {
            current = current->pnext;
        }
        Node* temp = current->pnext->pnext;
        delete current->pnext;
        current->pnext = temp;
        size--;
    }

    void Print()
    {
        Node* current = head;
        while (current != nullptr)
        {
            std::cout << current->data << ' ';
            current = current->pnext;
        }
    }

    bool search(T target)
    {
        Node* current = head;
        while (current->pnext != nullptr)
        {
            if (current->data == target)
                return true;
            current = current->pnext;
        }
        if (current->data == target)
            return true;
        return false;
    }

    void reverse()
    {
        Node* head2 = nullptr;
        Node* current = head;
        while (current != nullptr)
        {
            Node* temp = head2;
            head2 = new Node(current->data);
            head2->pnext = temp;
            current = current->pnext;
        }
        int temp = size;
        while(size)
            this->pop_front();
        size = temp;
        head = head2;
    }

    ~MyList()
    {
        while (size)
        {
            this->pop_front();
        }
    }

};
int main()
{
    MyList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.reverse();
    list.push_back(5);
    list.push_back(5);
    list.push_back(5);
    list.push_back(5);
    list.Print();
}