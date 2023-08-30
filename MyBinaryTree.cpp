#include <iostream>
#include <queue>
#include <stack>
class MyTree
{
private:

    struct Node
    {
        int data = 0;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(int data)
        {
            this->data = data;
        }
    };

    Node* head = nullptr;

    void recursive(int val, std::queue<Node*> q)
    {
        if (q.empty())
           return;
        if (q.front()->left != nullptr)
            q.push(q.front()->left);
        if (q.front()->right != nullptr)
            q.push(q.front()->right);
        q.pop();
        if (q.front()->left == nullptr)
        {
            q.front()->left = new Node(val);
            return;
        }
        if (q.front()->right == nullptr)
        {
            q.front()->right = new Node(val);
            return;

        }
        recursive(val, q);
    }

    void recursive2(Node* temp,Node* DeepestLeaf)
    {
        if (temp == nullptr)
            return;
        if (temp->left == DeepestLeaf)
        {
            delete temp->left;
            temp->left = nullptr;
            return;
        }
        if (temp->right == DeepestLeaf)
        {
            delete temp->right;
            temp->right = nullptr;
            return;
        }
        recursive2(temp->left, DeepestLeaf);
        recursive2(temp->right, DeepestLeaf);
    }

    Node* DeepestNode()
    {
        Node* DeepestLeaf = nullptr;
        int CurrentDepth = 0;
        int MaxDepth = 0;
        std::stack<Node*> s;
        s.push(head);
        Node* temp;
        while (!s.empty())
        {
            temp = s.top();
            s.pop();
            if (temp->right != nullptr)
            {
                s.push(temp->right);
                CurrentDepth++;
            }
            if (temp->left != nullptr)
            {
                s.push(temp->left);
                CurrentDepth++;
            }
            if (temp->left == nullptr && temp->right == nullptr)
            {
                if (CurrentDepth > MaxDepth)
                {
                    MaxDepth = CurrentDepth;
                    DeepestLeaf = temp;
                }
                CurrentDepth = 0;
            }
        }
        return DeepestLeaf;
    }

public:

    MyTree()
    {
        head = new Node(1);
        head->left = new Node(4);
        head->right = new Node(2);
        head->left->left = new Node(6);
        head->left->right = new Node(5);
        head->right->right = new Node(3);
    }

    void IterativeInsertion(int val)
    {
        if (head == nullptr)
        {
            head = new Node(val);
            return;
        }

        std::queue<Node*> q;
        q.push(head);
        while (!q.empty())
        {
            if (q.front()->left != nullptr)
            {
                q.push(q.front()->left);
            }
            else
            {
                q.front()->left = new Node(val);
                return;
            }
            if (q.front()->right != nullptr)
            {
                q.push(q.front()->right);
            }
            else
            {
                q.front()->right = new Node(val);
                return;
            }
            q.pop();
        }
    }

    void RecursiveInsertion(int val)
    {
        if (head == nullptr)
        {
            head = new Node(val);
            return;
        }
        std::queue<Node*> q;
        q.push(head);
        recursive(val,q);
    }

    void IterativeDeletion()
    {
        Node* DeepestLeaf = DeepestNode();
        std::stack<Node*> s;
        s.push(head);
        Node* temp;
        while(!s.empty())
        {
            temp = s.top();
            s.pop();
            if (temp->left != nullptr)
            {
                s.push(temp->left);
                if (temp->left == DeepestLeaf)
                {
                    delete temp->left;
                    temp->left = nullptr;
                    return;
                }
            }
            if (temp->right != nullptr)
            {
                s.push(temp->right);
                if (temp->right == DeepestLeaf)
                {
                    delete temp->right;
                    temp->right = nullptr;
                    return;
                }
            }
        }
    }

    void RecursiveDeletion()
    {
        Node* temp = head;
        recursive2(temp,DeepestNode());
    }

    void Print()
    {
        std::stack<Node*> s;
        s.push(head);
        Node* temp;
        while (!s.empty())
        {
            std::cout << s.top()->data << ' ';
            temp = s.top();
            s.pop();
            if (temp->left != nullptr)
                s.push(temp->left);
            if (temp->right != nullptr)
                s.push(temp->right);
        }
    }
};

int main()
{
    MyTree a;
    a.IterativeInsertion(16);
    a.Print();
}
