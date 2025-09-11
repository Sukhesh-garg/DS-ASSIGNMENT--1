#include <iostream>
using namespace std;

class stackk
{
private:
    char arr[1000];
    int top;

public:
    stackk() { top = -1; }

    bool push(char c)
    {
        if (top >= 1000 - 1)
        {
            cout << "stackk Overflow" << endl;
            return false;
        }
        arr[++top] = c;
        return true;
    }

    char pop()
    {
        if (top < 0)
        {
            cout << "stackk Underflow" << endl;
            return '\0';
        }
        return arr[top--];
    }

    bool isEmpty()
    {
        return top < 0;
    }
};

bool isBalanced(char *expr)
{
    stackk s;
    for (int i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
        {
            s.push(expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            if (s.isEmpty())
            {
                return false;
            }
            char top = s.pop();
            if ((expr[i] == ')' && top != '(') ||
                (expr[i] == '}' && top != '{') ||
                (expr[i] == ']' && top != '['))
            {
                return false;
            }
        }
    }
    return s.isEmpty();
}

int main()
{
    char expr[1000];
    cout << "Enter an expression: ";
    cin.getline(expr, 1000);

    if (isBalanced(expr))
    {
        cout << "The expression has balanced parentheses" << endl;
    }
    else
    {
        cout << "The expression does NOT have balanced parentheses" << endl;
    }

    return 0;
}