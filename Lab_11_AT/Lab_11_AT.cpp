#include <iostream>
#include <Windows.h>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;

	Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

void forwardTraversal(Node* head) {
	Node* curr = head;
	while (curr != nullptr) {
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}

void backwardTraversal(Node* head) {
	if (head == nullptr) return;

	Node* tail = head;
	while (tail->next != nullptr) {
		tail = tail->next;
	}

	Node* curr = tail;
	while (curr != nullptr) {
		cout << curr->data << " ";
		curr = curr->prev;
	}
	cout << endl;
}

Node* insertBegin(Node* head, int data) {
	Node* new_node = new Node(data);
	new_node->next = head;
	if (head != nullptr) {
		head->prev = new_node;
	}
	return new_node;
}

Node* insertEnd(Node* head, int data) {
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

Node* deleteFirst(Node* head) {
	if (head == nullptr) {
		return nullptr;
	}
	Node* temp = head;
	head = head->next;
	if (head != nullptr) {
		head->prev = nullptr;
	}
	delete temp;
	return head;
}


Node* deleteLast(Node* head) {
	if (head == nullptr) {
		return nullptr;
	}
	if (head->next == nullptr) {
		delete head;
		return nullptr;
	}
	Node* curr = head;
	while (curr->next != nullptr) {
		curr = curr->next;
	}
	curr->prev->next = nullptr;
	delete curr;
	return head;
}

Node* deleteMiddle(Node* head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}

	Node* slow = head;
	Node* fast = head;
	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow->prev != nullptr) {
		slow->prev->next = slow->next;
	}
	if (slow->next != nullptr) {
		slow->next->prev = slow->prev;
	}
	delete slow;
	return head;
}

void printList(Node* head) {
	Node* curr = head;
	
	while (curr != nullptr) {
		cout << curr->data << " ";
		curr = curr->next;
		
	}
	cout << " \n" ;

}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Node* head = new Node(2);
	head = insertEnd(head, 3);
	head = insertEnd(head, 4);
	head = insertEnd(head, 5);



	cout << "Друк оригінального списку		";
	printList(head);



	cout << "Додано останій елемент			";
	head = insertEnd(head, 6);
	printList(head);



	cout << "Додано перший елемент			";
	head = insertBegin(head, 1);
	printList(head);



	cout << "Прямий обхід списку			";
	forwardTraversal(head);



	cout << "Зворотний обхід списку			";
	backwardTraversal(head);



	head = deleteFirst(head);
	cout << "Видалення першого елемента		";
	printList(head);



	head = deleteLast(head);
	cout << "Видалення останнього елемента		";
	printList(head);



	head = deleteMiddle(head);
	cout << "Видалення середнього елемента		";
	printList(head);





	return 0;
}
