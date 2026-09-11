#include <iostream>
using namespace std;

template <typename T>
class SharedPtr
{
private:
    T* ptr;
    int* refCount;

public:

    // Constructor
    explicit SharedPtr(T* p = nullptr)
    {
        ptr = p;

        if (ptr)
            refCount = new int(1);
        else
            refCount = nullptr;
    }

    // Copy Constructor
    SharedPtr(const SharedPtr& other)
    {
        ptr = other.ptr;
        refCount = other.refCount;

        if (refCount)
            ++(*refCount);
    }

    // Copy Assignment
    SharedPtr& operator=(const SharedPtr& other)
    {
        if (this != &other)
        {
            release();

            ptr = other.ptr;
            refCount = other.refCount;

            if (refCount)
                ++(*refCount);
        }

        return *this;
    }

    // Destructor
    ~SharedPtr()
    {
        release();
    }

    // Dereference operator
    T& operator*() const
    {
        return *ptr;
    }

    // Arrow operator
    T* operator->() const
    {
        return ptr;
    }

    // Get raw pointer
    T* get() const
    {
        return ptr;
    }

    // Get reference count
    int use_count() const
    {
        return refCount ? *refCount : 0;
    }

private:

    void release()
    {
        if (refCount)
        {
            --(*refCount);

            if (*refCount == 0)
            {
                delete ptr;
                delete refCount;
            }
        }

        ptr = nullptr;
        refCount = nullptr;
    }
};


class Test
{
public:
    Test()
    {
        cout << "Constructor\n";
    }

    ~Test()
    {
        cout << "Destructor\n";
    }

    void show()
    {
        cout << "Hello SharedPtr\n";
    }
};


int main()
{
    SharedPtr<Test> p1(new Test);

    cout << "p1 count = " << p1.use_count() << endl;

    {
        SharedPtr<Test> p2 = p1;

        cout << "p1 count = " << p1.use_count() << endl;
        cout << "p2 count = " << p2.use_count() << endl;

        p2->show();
    }

    cout << "After p2 destroyed:\n";
    cout << "p1 count = " << p1.use_count() << endl;

    return 0;
}