
#include <iostream>
#include <math.h>

struct Node
{
    int data;
    Node* next;
};

void Add(Node* root, int data)
{
    Node* p = new Node;
    p->data = data;
    p->next = root->next;
    root->next = p;
}

void AddBack(Node* root, int data)
{
    Node* q = root;
    while (q->next != nullptr)
    {
        q = q->next;
    }
    Add(q, data);
}

void Print(Node* root)
{
    std::cout << "===" << std::endl;
    Node* p = root->next;
    while (p != nullptr)
    {
        std::cout << p->data << std::endl;
        p = p->next;
    }
    std::cout << "===" << std::endl;
}

void Free(Node* root)
{
    Node* p = root->next;
    while (p != nullptr)
    {
        Node* q = p->next;
        delete p;
        p = q;
    }
    root = nullptr;
}

bool Check_if_dec(Node* root)
{
    Node* q = root->next;
    Node* p = root->next->next;
    while (p != nullptr)
    {
        if ((q->data) < (p->data))
            return false;
        q = p;
        p = p->next;
    }
    return true;
}

bool Check_if_prime(int n)
{
    if (n == 2)
        return true;
    for (int i = 2; i < sqrt(n) + 1; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void Duplicate_Data(Node* root, int data)
{
    Node* p = root->next;
    while (p != nullptr) {
        if (p->data == data) {
            Add(p, data);
            p = p->next;
        }
        p = p->next;
    }
}

bool Сontains(int num, int contains) {
    while (num > 0) {
        if (num % 10 == contains) {
            return true;
        }
        num /= 10;
    }
    return false;
}

void Act_if_dec(Node* root)
{
    Node* q = root;
    Node* p = root->next;
    while (p != nullptr)
    {
        if (Check_if_prime(p->data) == true)
        {
            q->next = p->next;
            Node* tmp = p;
            p = p->next;
            delete tmp;
        }
        if (Check_if_prime(p->data) == false && Сontains(p->data, 8) == true)
        {
            Duplicate_Data(root, p->data);
            q = p;
            p = p->next;
        }
        q = p;
        p = p->next;

    }
}

void Act_if_inc(Node* root)
{
    Node* q = root;
    Node* p = root->next;
    while (p != nullptr) {
        while (p != nullptr) {
            if (q->data > p->data) {
                int tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
            p = p->next;
        }
        q = q->next;
        p = q->next;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Node* root = new Node;
    root->next = nullptr;
    int length;

    std::cout << "Сколько всего элементов последовательности?" << std::endl;
    std::cin >> length;
    std::cout << "Введите элементы по одному:" << std::endl;
    for (int i = 0; i < length; i++)
    {
        int elem;
        std::cin >> elem;
        AddBack(root, elem);
    }

    if (Check_if_dec(root) == true)
        Act_if_dec(root);
    else
        Act_if_inc(root);

    Print(root);

    Free(root);
    delete root;

    return 0;
}
