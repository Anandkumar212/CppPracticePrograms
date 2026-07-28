/*
    DOUBLY LINKED LIST - ALL OPERATIONS (C++)
    -------------------------------------------
    1. Insert at Beginning
    2. Insert at End
    3. Insert at Given Position
    4. Delete from Beginning
    5. Delete from End
    6. Delete from Given Position
    7. Search an Element
    8. Display Forward
    9. Display Backward
    10. Count Nodes
    11. Reverse the List
    12. Sort the List (Bubble Sort)
    13. Find Middle Element
*/

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node *prev;
    Node *next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        freeList();
    }

    // -----------------------------------------------
    // 1. Insert at Beginning
    void insertAtBeginning(int value) {
        Node *newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << value << " inserted at beginning.\n";
    }

    // -----------------------------------------------
    // 2. Insert at End
    void insertAtEnd(int value) {
        Node *newNode = new Node(value);

        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        cout << value << " inserted at end.\n";
    }

    // -----------------------------------------------
    // 3. Insert at Given Position (1-based indexing)
    void insertAtPosition(int value, int pos) {
        if (pos < 1) {
            cout << "Invalid position.\n";
            return;
        }

        if (pos == 1) {
            insertAtBeginning(value);
            return;
        }

        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Position out of range.\n";
            return;
        }

        // Insert at end if position is beyond last node
        if (temp == tail) {
            insertAtEnd(value);
            return;
        }

        Node *newNode = new Node(value);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        cout << value << " inserted at position " << pos << ".\n";
    }

    // -----------------------------------------------
    // 4. Delete from Beginning
    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = head;
        cout << temp->data << " deleted from beginning.\n";

        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    // -----------------------------------------------
    // 5. Delete from End
    void deleteAtEnd() {
        if (tail == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = tail;
        cout << temp->data << " deleted from end.\n";

        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    // -----------------------------------------------
    // 6. Delete from Given Position (1-based indexing)
    void deleteAtPosition(int pos) {
        if (head == nullptr || pos < 1) {
            cout << "Invalid operation.\n";
            return;
        }

        if (pos == 1) {
            deleteAtBeginning();
            return;
        }

        Node *temp = head;
        for (int i = 1; i < pos && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Position out of range.\n";
            return;
        }

        if (temp == tail) {
            deleteAtEnd();
            return;
        }

        cout << temp->data << " deleted from position " << pos << ".\n";
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    // -----------------------------------------------
    // 7. Search an Element (returns position, -1 if not found)
    int search(int value) {
        Node *temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == value)
                return pos;
            temp = temp->next;
            pos++;
        }
        return -1;
    }

    // -----------------------------------------------
    // 8. Display Forward (head to tail)
    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        cout << "Forward: NULL <-> ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // -----------------------------------------------
    // 9. Display Backward (tail to head)
    void displayBackward() {
        if (tail == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = tail;
        cout << "Backward: NULL <-> ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }

    // -----------------------------------------------
    // 10. Count Nodes
    int countNodes() {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // -----------------------------------------------
    // 11. Reverse the List (swap prev/next for every node)
    void reverse() {
        Node *curr = head;
        Node *temp = nullptr;

        while (curr != nullptr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev; // move to next node (which is old prev)
        }

        temp = head;
        head = tail;
        tail = temp;

        cout << "List reversed.\n";
    }

    // -----------------------------------------------
    // 12. Sort the List (Bubble Sort - ascending, swap data only)
    void sortList() {
        if (head == nullptr) return;
        bool swapped;
        Node *ptr1;
        Node *lastNode = nullptr;

        do {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lastNode) {
                if (ptr1->data > ptr1->next->data) {
                    swap(ptr1->data, ptr1->next->data);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lastNode = ptr1;
        } while (swapped);

        cout << "List sorted in ascending order.\n";
    }

    // -----------------------------------------------
    // 13. Find Middle Element (Slow-Fast Pointer approach)
    void findMiddle() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << "\n";
    }

    // -----------------------------------------------
    // Free entire list (memory cleanup)
    void freeList() {
        Node *temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

// ---------------------------------------------------
// MENU DRIVEN PROGRAM
int main() {
    DoublyLinkedList list;
    int choice, value, pos;

    while (true) {
        cout << "\n===== DOUBLY LINKED LIST OPERATIONS =====\n";
        cout << "1.  Insert at Beginning\n";
        cout << "2.  Insert at End\n";
        cout << "3.  Insert at Position\n";
        cout << "4.  Delete from Beginning\n";
        cout << "5.  Delete from End\n";
        cout << "6.  Delete from Position\n";
        cout << "7.  Search Element\n";
        cout << "8.  Display Forward\n";
        cout << "9.  Display Backward\n";
        cout << "10. Count Nodes\n";
        cout << "11. Reverse List\n";
        cout << "12. Sort List\n";
        cout << "13. Find Middle Element\n";
        cout << "0.  Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> pos;
                list.insertAtPosition(value, pos);
                break;
            case 4:
                list.deleteAtBeginning();
                break;
            case 5:
                list.deleteAtEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                list.deleteAtPosition(pos);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                pos = list.search(value);
                if (pos != -1)
                    cout << value << " found at position " << pos << ".\n";
                else
                    cout << value << " not found in the list.\n";
                break;
            case 8:
                list.displayForward();
                break;
            case 9:
                list.displayBackward();
                break;
            case 10:
                cout << "Number of nodes: " << list.countNodes() << "\n";
                break;
            case 11:
                list.reverse();
                break;
            case 12:
                list.sortList();
                break;
            case 13:
                list.findMiddle();
                break;
            case 0:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
