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

void dailyTemperatures(int temperatures[], int n, int answer[])
{
    stackk s;
    for (int i = 0; i < n; i++)
    {
        answer[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        while (!s.isEmpty() && temperatures[s.peek()] < temperatures[i])
        {
            int prevIndex = s.pop();
            answer[prevIndex] = i - prevIndex;
        }
        s.push(i);
    }
}

int main()
{
    int n;
    cout << "Enter the number of days: " << endl;
    cin >> n;
    int temperatures[100], answer[100];
    cout << "Enter " << n << " temperatures: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> temperatures[i];
    }
    dailyTemperatures(temperatures, n, answer);
    cout << "Days until warmer temperature: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << answer[i] << " " << endl;
    }
    return 0;
}