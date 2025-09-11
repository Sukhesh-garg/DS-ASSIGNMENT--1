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
        top++;
        arr[top] = value;
        return true;
    }

    int pop()
    {
        if (top < 0)
        {
            cout << "stackk Underflow" << endl;
            return 0;
        }
        return arr[top--];
    }

    bool isEmpty()
    {
        return top < 0;
    }
};
int results(char *expressions)
{
    stackk s;

    for (int i = 0; expressions[i] != 0; i++)
    {
        char c = expressions[i];
        if (c == ' ')
        {
            continue;
        }
        if (c >= '0' && c <= '9')
        {
            int num = c - '0';
            s.push(num);
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            int num2 = s.pop();
            int num1 = s.pop();
            int result;
            if (c == '+')
            {
                result = num1 + num2;
            }
            else if (c == '-')
            {
                result = num1 - num2;
            }
            else if (c == '*')
            {
                result = num1 * num2;
            }
            else if (c == '/')
            {
                if (num2 == 0)
                {
                    cout << "Division by zero!" << endl;
                    return 0;
                }
                result = num1 / num2;
            }
            s.push(result);
        }
    }
    if (!s.isEmpty())
    {
        return s.pop();
    }
    return 0;
}

int main()
{
    char expressions[100];
    cout << "Enter a postfix expression: ";
    cin.getline(expressions, 100);
    int result = results(expressions);
    cout << "Result: " << result << endl;

    return 0;
}