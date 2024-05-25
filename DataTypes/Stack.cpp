#include <iostream>
#include <string>

using namespace std;

class Stack
{
private:
    short arr[30];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(short value)
    {
        if (top >= 29)
        {
            cout << "Stack overflow" << endl;
        }
        else
        {
            arr[++top] = value;
        }
    }

    short pop()
    {
        if (top < 0)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        else
        {
            return arr[top--];
        }
    }

    short peek() const
    {
        if (top < 0)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    bool isEmpty() const
    {
        return top < 0;
    }

    ~Stack()
    {
        cout << "constructor Destroyed" << endl;
    }
};

int main()
{
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is: " << stack.peek() << endl;

    cout << "Elements: " << endl;

    while (!stack.isEmpty())
    {
        cout << stack.pop() << " ";
    }
    cout << endl;

    return 0;
}
