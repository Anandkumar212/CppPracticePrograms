#include <iostream>
#include <cstring>
#include <utility>

class MyString
{
private:
    char* data;
    size_t len;

public:

    // 1. Default Constructor
    MyString() : data(nullptr), len(0)
    {
    }

    // 2. Constructor from C-style string
    MyString(const char* str)
    {
        if (str)
        {
            len = std::strlen(str);

            data = new char[len + 1];

            std::strcpy(data, str);
        }
        else
        {
            data = nullptr;
            len = 0;
        }
    }

    // 3. Copy Constructor
    MyString(const MyString& other)
    {
        len = other.len;

        if (other.data)
        {
            data = new char[len + 1];

            std::strcpy(data, other.data);
        }
        else
        {
            data = nullptr;
        }
    }

    // 4. Move Constructor
    MyString(MyString&& other) noexcept
    {
        data = other.data;
        len = other.len;

        other.data = nullptr;
        other.len = 0;
    }

    // 5. Copy Assignment Operator
    MyString& operator=(const MyString& other)
    {
        if (this != &other)
        {
            delete[] data;

            len = other.len;

            if (other.data)
            {
                data = new char[len + 1];

                std::strcpy(data, other.data);
            }
            else
            {
                data = nullptr;
            }
        }

        return *this;
    }

    // 6. Move Assignment Operator
    MyString& operator=(MyString&& other) noexcept
    {
        if (this != &other)
        {
            delete[] data;

            data = other.data;
            len = other.len;

            other.data = nullptr;
            other.len = 0;
        }

        return *this;
    }

    // 7. Concatenation using +
    MyString operator+(const MyString& other) const
    {
        MyString result;

        result.len = len + other.len;

        result.data = new char[result.len + 1];

        if (data)
            std::strcpy(result.data, data);
        else
            result.data[0] = '\0';

        if (other.data)
            std::strcat(result.data, other.data);

        return result;
    }

    // 8. Get C-style string
    const char* c_str() const
    {
        return data ? data : "";
    }

    // 9. Destructor
    ~MyString()
    {
        delete[] data;
    }
};


// Output operator
std::ostream& operator<<(std::ostream& os, const MyString& str)
{
    os << str.c_str();
    return os;
}


int main()
{
    MyString s1("Hello");
    MyString s2(" World");

    std::cout << "s1 = " << s1 << std::endl;
    std::cout << "s2 = " << s2 << std::endl;


    // Concatenation
    MyString s3 = s1 + s2;

    std::cout << "Concatenated string = "
              << s3 << std::endl;


    // Copy Constructor
    MyString s4 = s1;

    std::cout << "Copied string = "
              << s4 << std::endl;


    // Copy Assignment
    MyString s5;

    s5 = s2;

    std::cout << "Copy assigned string = "
              << s5 << std::endl;


    // Move Constructor
    MyString s6 = std::move(s1);

    std::cout << "Moved string = "
              << s6 << std::endl;


    // Move Assignment
    MyString s7;

    s7 = std::move(s2);

    std::cout << "Move assigned string = "
              << s7 << std::endl;


    return 0;
}