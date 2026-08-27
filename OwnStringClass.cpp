#include <iostream>
using namespace std;

class String
{
    char *str;

public:

    // Parameterized Constructor
    String(const char *s)
    {
        int length = stringLength(s);

        str = new char[length + 1];

        strcopy(str, s);
    }

    // Copy Constructor
    String(const String& obj)
    {
        int length = stringLength(obj.str);

        str = new char[length + 1];

        strcopy(str, obj.str);
    }

    // Destructor
    ~String()
    {
        delete[] str;
    }

    void print()
    {
        cout << str << endl;
    }

private:

    int stringLength(const char *s)
    {
        int len = 0;

        while (s[len] != '\0')
        {
            len++;
        }

        return len;
    }

    void strcopy(char *dest, const char *src)
    {
        int i = 0;

        while (src[i] != '\0')
        {
            dest[i] = src[i];
            i++;
        }

        dest[i] = '\0';
    }
};

int main()
{
    String s("anand");

    // Copy Constructor called
    String s1 = s;

    s1.print();

    return 0;
}