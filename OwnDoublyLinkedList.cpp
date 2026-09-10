#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoubleLinkedList {

    Node* head;

public:

    DoubleLinkedList() {
        head = nullptr;
    }

    void setHead(Node* n) {
        head = n;
    }

    // ---------------- FORWARD TRAVERSE ----------------

    void forwardTraverse() {

        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << "---";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // ---------------- BACKWARD TRAVERSE ----------------

    void backwardTraverse() {

        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        // Go to last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // Traverse backwards
        while (temp != nullptr) {
            cout << temp->data << "---";
            temp = temp->prev;
        }

        cout << "NULL\n";
    }

    // ---------------- INSERT AT BEGINNING ----------------

    void insertNodeAtBeginning(int value) {

        Node* newNode = new Node(value);

        // Empty list
        if (head == nullptr) {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;

        head = newNode;
    }

    // ---------------- INSERT AT END ----------------

    void insertNodeAtLast(int value) {

        Node* newNode = new Node(value);

        // Empty list
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;

        // Find last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    // ---------------- INSERT AT POSITION ----------------

    void insertNodeAtPosition(int value, int pos) {

        if (pos < 1) {
            cout << "Invalid position\n";
            return;
        }

        if (pos == 1) {
            insertNodeAtBeginning(value);
            return;
        }

        if (head == nullptr) {
            cout << "Invalid position\n";
            return;
        }

        Node* temp = head;

        // Move to node BEFORE required position
        for (int i = 1; i < pos - 1; i++) {

            if (temp->next == nullptr) {
                cout << "Invalid position\n";
                return;
            }

            temp = temp->next;
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }

    // ---------------- DELETE AT BEGINNING ----------------

    void deleteNodeAtBeginning() {

        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        // Only one node
        if (head->next == nullptr) {
            head = nullptr;
            delete temp;
            return;
        }

        head = head->next;
        head->prev = nullptr;

        delete temp;
    }

    // ---------------- DELETE AT END ----------------

    void deleteAtEnd() {

        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        // Only one node
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;

        // Find last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        Node* lastNode = temp->prev;

        lastNode->next = nullptr;

        delete temp;
    }

    // ---------------- DELETE AT POSITION ----------------

    void deleteAtMiddle(int pos) {

        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        if (pos < 1) {
            cout << "Invalid position\n";
            return;
        }

        if (pos == 1) {
            deleteNodeAtBeginning();
            return;
        }

        Node* temp = head;

        // Move to node BEFORE position
        for (int i = 1; i < pos - 1; i++) {

            if (temp->next == nullptr) {
                cout << "Invalid position\n";
                return;
            }

            temp = temp->next;
        }

        Node* delNode = temp->next;

        if (delNode == nullptr) {
            cout << "Invalid position\n";
            return;
        }

        temp->next = delNode->next;

        if (delNode->next != nullptr) {
            delNode->next->prev = temp;
        }

        delete delNode;
    }

    // ---------------- REVERSE ----------------

    void reverseDoubleLinkedList() {

        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {

            // Swap next and prev
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            // Move to next node in original direction
            current = current->prev;
        }

        // temp is pointing to the old head's previous node
        if (temp != nullptr) {
            head = temp->prev;
        }
    }
};

int main() {

    Node* n1 = new Node(10);
    Node* n2 = new Node(20);

    n1->next = n2;
    n2->prev = n1;

    DoubleLinkedList dl;

    dl.setHead(n1);

    cout << "Initial list:\n";
    dl.forwardTraverse();

    cout << "\nInsert at beginning:\n";
    dl.insertNodeAtBeginning(5);
    dl.forwardTraverse();

    cout << "\nInsert at last:\n";
    dl.insertNodeAtLast(25);
    dl.forwardTraverse();

    cout << "\nBackward traverse:\n";
    dl.backwardTraverse();

    cout << "\nInsert 15 at position 3:\n";
    dl.insertNodeAtPosition(15, 3);
    dl.forwardTraverse();

    cout << "\nBackward traverse:\n";
    dl.backwardTraverse();

    cout << "\nDelete beginning:\n";
    dl.deleteNodeAtBeginning();
    dl.forwardTraverse();

    cout << "\nDelete end:\n";
    dl.deleteAtEnd();
    dl.forwardTraverse();

    cout << "\nDelete position 2:\n";
    dl.deleteAtMiddle(2);
    dl.forwardTraverse();

    cout << "\nReverse list:\n";
    dl.reverseDoubleLinkedList();
    dl.forwardTraverse();

    cout << "\nBackward after reverse:\n";
    dl.backwardTraverse();

    return 0;
}