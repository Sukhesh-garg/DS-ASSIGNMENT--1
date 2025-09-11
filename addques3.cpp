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

void findNextGreater(int arr[], int n, int result[])
{
    stackk s;
    for (int i = 0; i < n; i++)
    {
        result[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        while (!s.isEmpty() && arr[s.peek()] < arr[i])
        {
            result[s.pop()] = arr[i];
        }
        s.push(i);
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    int arr[100], result[100];
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    findNextGreater(arr, n, result);
    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " " << endl;
    }
    return 0;
}