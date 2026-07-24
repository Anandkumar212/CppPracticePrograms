#include <iostream>
using namespace std;

class Test
{
public:
    int* ptr;

    // Constructor
    Test(int x)
    {
        ptr = new int(x);
        cout << "Constructor\n";
    }

    // Copy Constructor (Deep Copy)
    Test(const Test& t)
    {
        ptr = new int(*t.ptr);
        cout << "Copy Constructor\n";
    }

    // Copy Assignment Operator
    Test& operator=(const Test& t)
    {
        if (this != &t)
        {
            delete ptr;
            ptr = new int(*t.ptr);
        }

        cout << "Copy Assignment\n";
        return *this;
    }

    // Move Constructor
    Test(Test&& t) noexcept
    {
        ptr = t.ptr;
        t.ptr = nullptr;

        cout << "Move Constructor\n";
    }

    // Move Assignment Operator
    Test& operator=(Test&& t) noexcept
    {
        if (this != &t)
        {
            delete ptr;

            ptr = t.ptr;
            t.ptr = nullptr;
        }

        cout << "Move Assignment\n";
        return *this;
    }

    void display() const
    {
        if (ptr)
            cout << "Value = " << *ptr << endl;
        else
            cout << "Pointer is nullptr" << endl;
    }

    // Destructor
    ~Test()
    {
        delete ptr;
        cout << "Destructor\n";
    }
};

int main()
{
    Test t1(10);

    // Copy Constructor
    Test t2 = t1;

    // Copy Assignment
    Test t3(30);
    t3 = t1;

    // Move Constructor
    Test t4 = std::move(t1);

    // Move Assignment
    Test t5(50);
    t5 = std::move(t2);

    cout << "\nObjects:\n";

    t3.display();
    t4.display();
    t5.display();

    cout << "\nMoved-from objects:\n";

    t1.display();
    t2.display();

    return 0;
}
