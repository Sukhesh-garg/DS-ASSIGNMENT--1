#include <iostream>
using namespace std;

class stackk
{
private:
    char arr[100];
    int top;

public:
    stackk() { top = -1; }

    bool push(char c)
    {
        if (top >= 100 - 1)
        {
            cout << "stackk Overflow" << endl;
            return false;
        }
        top++;
        arr[top] = c;
        return true;
    }

    char pop()
    {
        if (top < 0)
        {
            cout << "stackk Underflow" << endl;
            return false;
        }
        return arr[top--];
    }

    bool isEmpty()
    {
        return top < 0;
    }
};
int stringLength(const char *str)
{
    int len = 0;
    while (str[len] != 0)
        len++;
    return len;
}
void reverseString(char *str)
{
    stackk s;
    int len = stringLength(str);
    for (int i = 0; i < len; i++)
    {
        s.push(str[i]);
    }
    for (int i = 0; i < len; i++)
    {
        str[i] = s.pop();
    }
}

int main()
{
    char input[1000];
    cout << "Enter a string to reverse: ";
    cin.getline(input, 1000);

    reverseString(input);
    cout << "Reversed string: " << input << endl;

    return 0;
}