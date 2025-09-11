#include <iostream>
using namespace std;

class stackk
{
private:
    static const int MAX = 100;
    int arr[MAX];
    int top;

public:
    stackk() { top = -1; }
    bool push(int value)
    {
        if (top >= MAX - 1)
        {
            cout << "stackk Overflow" << endl;
            return false;
        }
        arr[++top] = value;
        return true;
    }

    int pop()
    {
        if (top < 0)
        {
            cout << "stackk Underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek()
    {
        if (top < 0)
        {
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top < 0;
    }
};

bool canSortArray(int A[], int n)
{
    stackk s;
    int lastB = -2147483648;
    for (int i = 0; i < n; i++)
    {
        s.push(A[i]);
        while (!s.isEmpty() && s.peek() >= lastB)
        {
            lastB = s.pop();
        }
    }
    while (!s.isEmpty())
    {
        if (s.peek() < lastB)
        {
            return false;
        }
        lastB = s.pop();
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int A[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    if (canSortArray(A, n))
    {
        cout << "Yes, array can be sorted into B in ascending order" << endl;
    }
    else
    {
        cout << "No, array cannot be sorted into B in ascending order" << endl;
    }
    return 0;
}