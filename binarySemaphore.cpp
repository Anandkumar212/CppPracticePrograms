#include <iostream>
#include <thread>
#include <semaphore>

using namespace std;

binary_semaphore semPrint(1);   // print() goes first
binary_semaphore semNumber(0);  // eventNumber() waits

void print()
{
    for (int i = 0; i <= 10; i++)
    {
        semPrint.acquire();

        cout << "thread program " << i << endl;

        semNumber.release();
    }
}

void eventNumber(int n)
{
    for (int i = 0; i <= n; i++)
    {
        semNumber.acquire();

        if (i % 2 == 0)
            cout << "Even Number: " << i << endl;
        else
            cout << "Odd Number: " << i << endl;

        semPrint.release();
    }
}

int main()
{
    thread t1(print);
    thread t2(eventNumber, 10);

    t1.join();
    t2.join();
}
