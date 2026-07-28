/*
    SINGLY LINKED LIST - ALL OPERATIONS (C++)
    ------------------------------------------
    1. Insert at Beginning
    2. Insert at End
    3. Insert at Given Position
    4. Delete from Beginning
    5. Delete from End
    6. Delete from Given Position
    7. Search an Element
    8. Display the List
    9. Count Nodes
    10. Reverse the List
    11. Sort the List (Bubble Sort)
    12. Find Middle Element
    13. Detect Loop (Floyd's Cycle Detection)
*/

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        freeList();
    }

    // -----------------------------------------------
    // 1. Insert at Beginning
    void insertAtBeginning(int value) {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << value << " inserted at beginning.\n";
    }

    // -----------------------------------------------
    // 2. Insert at End
    void insertAtEnd(int value) {
        Node *newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            cout << value << " inserted at end.\n";
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
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

        Node *newNode = new Node(value);
        newNode->next = temp->next;
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
        head = head->next;
        cout << temp->data << " deleted from beginning.\n";
        delete temp;
    }

    // -----------------------------------------------
    // 5. Delete from End
    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->next == nullptr) {
            cout << head->data << " deleted from end.\n";
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;

        cout << temp->next->data << " deleted from end.\n";
        delete temp->next;
        temp->next = nullptr;
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
        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of range.\n";
            return;
        }

        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        cout << toDelete->data << " deleted from position " << pos << ".\n";
        delete toDelete;
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
    // 8. Display the List
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // -----------------------------------------------
    // 9. Count Nodes
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
    // 10. Reverse the List
    void reverse() {
        Node *prev = nullptr, *curr = head, *next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        cout << "List reversed.\n";
    }

    // -----------------------------------------------
    // 11. Sort the List (Bubble Sort - ascending)
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
    // 12. Find Middle Element (Slow-Fast Pointer approach)
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
    // 13. Detect Loop (Floyd's Cycle Detection Algorithm)
    void detectLoop() {
        Node *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                cout << "Loop detected in the list.\n";
                return;
            }
        }
        cout << "No loop detected.\n";
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
    }
};

// ---------------------------------------------------
// MENU DRIVEN PROGRAM
int main() {
    LinkedList list;
    int choice, value, pos;

    while (true) {
        cout << "\n===== SINGLY LINKED LIST OPERATIONS =====\n";
        cout << "1.  Insert at Beginning\n";
        cout << "2.  Insert at End\n";
        cout << "3.  Insert at Position\n";
        cout << "4.  Delete from Beginning\n";
        cout << "5.  Delete from End\n";
        cout << "6.  Delete from Position\n";
        cout << "7.  Search Element\n";
        cout << "8.  Display List\n";
        cout << "9.  Count Nodes\n";
        cout << "10. Reverse List\n";
        cout << "11. Sort List\n";
        cout << "12. Find Middle Element\n";
        cout << "13. Detect Loop\n";
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
                list.display();
                break;
            case 9:
                cout << "Number of nodes: " << list.countNodes() << "\n";
                break;
            case 10:
                list.reverse();
                break;
            case 11:
                list.sortList();
                break;
            case 12:
                list.findMiddle();
                break;
            case 13:
                list.detectLoop();
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
