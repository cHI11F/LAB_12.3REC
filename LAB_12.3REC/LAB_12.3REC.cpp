#include <iostream>
using namespace std;

// Структура, що представляє вузол двунаправленого списку
struct Node {
    int data;     // Дані вузла
    Node* prev;   // Вказівник на попередній вузол
    Node* next;   // Вказівник на наступний вузол
};

// Функція для створення двунаправленого списку на основі масиву значень
Node* createListHelper(int values[], int size, int index) {
    if (index >= size) {
        return nullptr;
    }
    Node* newNode = new Node();
    newNode->data = values[index];
    newNode->prev = nullptr;
    newNode->next = createListHelper(values, size, index + 1);

    if (newNode->next != nullptr) {
        newNode->next->prev = newNode;
    }
    return newNode;
}

Node* createList(int values[], int size) {
    return createListHelper(values, size, 0);
}

// Функція для вилучення вузла зі списку
Node* deleteNode(Node* head, int valueToDelete) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->data == valueToDelete) {
        Node* nextNode = head->next;
        delete head;
        if (nextNode != nullptr) {
            nextNode->prev = nullptr;
        }
        return nextNode;
    }
    head->next = deleteNode(head->next, valueToDelete);
    if (head->next != nullptr) {
        head->next->prev = head;
    }
    return head;
}

// Функція для виведення значень усіх вузлів у списку
void printList(Node* head) {
    if (head == nullptr) {
        cout << endl;
        return;
    }
    cout << head->data << " ";
    printList(head->next);
}

// Функція для видалення всього списку та звільнення пам'яті
void deleteList(Node* head) {
    if (head == nullptr) {
        return;
    }
    deleteList(head->next);
    delete head;
}

int main() {

    int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };  // Масив значень для створення списку
    int size = sizeof(values) / sizeof(values[0]);  // Розмір масиву

    Node* head = createList(values, size);  // Створення двунаправленого списку

    cout << "Список елементів:" << endl;
    printList(head);  // Виведення елементів списку

    int valueToDelete;
    cout << "Введіть значення для видалення: ";
    cin >> valueToDelete;

    head = deleteNode(head, valueToDelete); // Видалення вузла зі списку

    cout << "Список після видалення:" << endl;
    printList(head);  // Виведення елементів списку після видалення

    deleteList(head);  // Видалення списку та звільнення пам'яті

    return 0;
}
