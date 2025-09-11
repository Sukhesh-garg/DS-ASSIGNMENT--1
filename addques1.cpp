#include <iostream>
using namespace std;

class stackk
{
private:
    int arr[100];
    int top;

public:
    stackk() { top = -1; }

    bool push(int value)
    {
        if (top >= 100 - 1)
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

void findNearestSmaller(int A[], int n, int result[])
{
    stackk s;
    for (int i = 0; i < n; i++)
    {
        while (!s.isEmpty() && s.peek() >= A[i])
        {
            s.pop();
        }
        result[i] = s.isEmpty() ? -1 : s.peek();
        s.push(A[i]);
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int A[100], result[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    findNearestSmaller(A, n, result);
    cout << "Nearest smaller elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " " << endl;
    }
    return 0;
}