
#include <iostream>
#include <string>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void Add(Node* head, int data) {
    Node* p = new Node;
    p->data = data;
    p->next = head->next;
    p->prev = head;
    head->next->prev = p;
    head->next = p;
}

void AddBack(Node* head, int data) {
    Node* q = head;
    while (q->next->next != nullptr)
    {
        q = q->next;
    }
    Add(q, data);
}

void Print(Node* head) {
    Node* p = head->next;
    std::cout << "===" << std::endl;
    while (p->next != nullptr) {
        std::cout << p->data << std::endl;
        p = p->next;
    }
    std::cout << "===" << std::endl;
}

bool Ñontains(int num, int contains) {
    while (num > 0) {
        if (num % 10 == contains) {
            return true;
        }
        num /= 10;
    }
    return false;
}

bool CheckIfIncLeftToRight(Node* head) {
    Node* q = head->next;
    Node* p = head->next->next;
    while (p->next != nullptr) {
        if ((q->data) > (p->data))
            return false;
        q = p;
        p = p->next;
    }
    return true;
}

bool CheckIfIncRightToLeft(Node* tail) {
    Node* q = tail->prev;
    Node* p = tail->prev->prev;
    while (p->prev != nullptr) {
        if ((q->data) > (p->data))
            return false;
        q = p;
        p = p->prev;
    }
    return true;
}

void DeleteByData(Node* head, int data) {
    Node* q = head;
    Node* p = head->next;
    while (p != nullptr) {
        if (p->data == data) {
            p = p->next;
            p->prev = q;
            q->next = p;
        }
        else {
            q = p;
            p = p->next;
        }
    }
}

void DuplicateByData(Node* head, int data) {
    Node* p = head->next;
    while (p != nullptr) {
        if (p->data == data) {
            Add(p, data);
            p = p->next;
        }
        p = p->next;
    }
}

void MainAct(Node* head) {
    Node* q = head;
    Node* p = head->next;
    while (p->next != nullptr) {
        if (Ñontains(p->data, 2) == false && Ñontains(p->data, 4) == false && Ñontains(p->data, 6) == false) {
            DeleteByData(head, p->data);
        }
        if (Ñontains(p->data, 6) == true && Ñontains(p->data, 9) == true) {
            DuplicateByData(head, p->data);
            q = q->next;
            p = p->next;
        }
        q = q->next;
        p = p->next;
    }
}

void ActIfElse(Node* head) {
    Node* q = head;
    Node* p = head->next;
    while (p->next != nullptr) {
        while (p->next != nullptr) {
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

    Node* head = new Node;
    Node* tail = new Node;
    head->prev = nullptr;
    head->next = tail;
    tail->prev = head;
    tail->next = nullptr;

    int length;
    std::cout << "Ñêîëüêî âñåãî ýëåìåíòîâ â ïîñëåäîâàòåëüíîñòè?" << std::endl;
    std::cin >> length;
    std::cout << "Ââåäèòå ýëåìåíòû ïî îäíîìó:" << std::endl;
    for (int i = 0; i < length; i++) {
        int n;
        std::cin >> n;
        AddBack(head, n);
    }

    if (CheckIfIncLeftToRight(head) == true || CheckIfIncRightToLeft(tail) == true) {
        MainAct(head);
    }
    else {
        ActIfElse(head);
    }

    Print(head);

    return 0;
}
