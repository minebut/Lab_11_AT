#include <iostream>
#include <Windows.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};


void forwardTraversal(Node* head)// Функція для прямого обходу списку 
{
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}


void backwardTraversal(Node* tail)// Функція для зворотного обходу списку 
{
    Node* curr = tail;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

Node* insertEnd(Node* head, int data) // Функція для вставки нового елемента в кінець списку
{
    Node* new_node = new Node(data);
    if (head == nullptr) {
       
        return new_node;
    }
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = new_node;
    new_node->prev = curr;
    return head;
}

void printList(Node* head) 
{
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Node* head = new Node(2);
    Node* temp1 = new Node(3);
    Node* temp2 = new Node(4);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;

   
    cout << "Друк оригінального списку ";
    printList(head);

    
    head = insertEnd(head, 1);

    
    cout << "Після додавання одного елемента в список ";
    printList(head);

    
    cout << "Прямий обхід списку ";
    forwardTraversal(head);

    
    Node* tail = temp2;
    cout << "Обратний обхід списку ";
    backwardTraversal(tail);

    return 0;
}
