#include <iostream>
using namespace std;

class Stack
{
private:
    char arr[100];
    int top;

public:
    Stack() { top = -1; }

    bool push(char c)
    {
        if (top >= 100 - 1)
        {
            cout << "Stack Overflow" << endl;
            return false;
        }
        arr[++top] = c;
        return true;
    }

    char pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
            return '\0';
        }
        return arr[top--];
    }

    char peek()
    {
        if (top < 0)
        {
            return '\0';
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top < 0;
    }
};

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op)
{
    if (op == '*' || op == '/')
    {
        return 2;
    }
    if (op == '+' || op == '-')
    {
        return 1;
    }
    return 0;
}

void infixToPostfix(char *infix, char *postfix)
{
    Stack s;
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix[j++] = s.pop();
            }
            if (!s.isEmpty() && s.peek() == '(')
            {
                s.pop();
            }
        }
        else if (isOperator(c))
        {
            while (!s.isEmpty() && s.peek() != '(' && precedence(s.peek()) >= precedence(c))
            {
                postfix[j++] = s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty())
    {
        if (s.peek() != '(')
        {
            postfix[j++] = s.pop();
        }
        else
        {
            s.pop();
        }
    }

    postfix[j] = 0;
}

int main()
{
    char infix[100], postfix[100];
    cout << "Enter an infix expression: ";
    cin.getline(infix, 100);

    infixToPostfix(infix, postfix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}