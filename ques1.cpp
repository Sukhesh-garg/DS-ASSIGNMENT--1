#include <iostream>
using namespace std;
class stackk
{
    int arr[100], top;

public:
    stackk()
    {
        top = -1;
    }
    void push(int x)
    {
        if (top == 100 - 1)
        {
            cout << "stackk Overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = x;
            cout << x << " pushed into stackk" << endl;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "stackk Underflow!" << endl;
        }
        else
        {
            cout << arr[top] << " popped from stackk" << endl;
            top = top - 1;
        }
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    bool isFull()
    {
        return (top == 100 - 1);
    }
    void peek()
    {
        if (top == -1)
        {
            cout << "stackk is Empty!\n";
        }
        else
        {
            cout << "Top element is: " << arr[top] << endl;
        }
    }
    void display()
    {
        if (top == -1)
        {
            cout << "stackk is Empty!\n";
        }
        else
        {
            cout << "stackk elements are: ";
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    stackk st;
    int choice, val;
    do
    {
        cout << "Menu" << endl;
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. isEmpty\n6. isFull\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> val;
            st.push(val);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            st.peek();
            break;
        case 4:
            st.display();
            break;
        case 5:
            cout << (st.isEmpty() ? "stackk is Empty\n" : "stackk is Not Empty\n");
            break;
        case 6:
            cout << (st.isFull() ? "stackk is Full\n" : "stackk is Not Full\n");
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid Choice!\n";
        }
    } while (choice != 7);
    return 0;
}