#include <iostream>
using namespace std;

int main()
{
    char ch;
    cout << "Enter a character: " << endl;
    cin >> ch;
    if (ch >= 'A' && ch <= 'Z')
    {
        ch = ch + 32;
        cout << "Lowercase character: " << ch << endl;
    }
    else
    {
        cout << ch << endl;
    }
    return 0;
}