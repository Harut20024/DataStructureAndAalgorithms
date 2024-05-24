#include <iostream>
using namespace std;

class List
{
private:
    int value;
    List *ptr = NULL;
public:
    List(int value) { this->value = value; }

    void setNext(List* next) {
        ptr = next;
    }

    List* getNext() const {
        return ptr;
    }

    int getValue() const {
        return value;
    }
};

int main()
{
    List node1(1);
    List node2(2);
    List node3(3);

    node1.setNext(&node2);
    node2.setNext(&node3);

    List* current = &node1;
    while (current != NULL) {
        cout << current->getValue() << endl;
        current = current->getNext();
    }

    return 0;
}
