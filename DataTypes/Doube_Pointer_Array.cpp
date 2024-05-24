#include <iostream>
#include <string>
using namespace std;

class Base
{

public:
    virtual void print() = 0;
    virtual ~Base() = default;
};

class Int : public Base
{
private:
    int value;

public:
    Int(int value) { this->value = value; };
    void print()
    {
        cout << value << endl;
    }
};
class Char : public Base
{
private:
    char value;

public:
    Char(char value) { this->value = value; };
    void print()
    {
        cout << value << endl;
    }
};

class String : public Base
{
private:
    string value;

public:
    String(string value) { this->value = value; };
    void print()
    {
        cout << value << endl;
    }
};

int main()
{
    Base **arr = new Base *[3];
    arr[0] = new Int(1);
    arr[1] = new String("hello");
    arr[2] = new Char('a');

    for (int i = 0; i < 3; ++i)
    {
        arr[i]->print();
    }

    for (int i = 0; i < 3; ++i)
    {
        delete arr[i];
    }
    delete[] arr;

    return 0;
}
