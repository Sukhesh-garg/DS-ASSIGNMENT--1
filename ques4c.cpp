#include <iostream>
using namespace std;
int main()
{
    string str, result;
    cout << "Enter a string: ";
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != 'a' && str[i] != 'A' &&
            str[i] != 'e' && str[i] != 'E' &&
            str[i] != 'i' && str[i] != 'I' &&
            str[i] != 'o' && str[i] != 'O' &&
            str[i] != 'u' && str[i] != 'U')
        {
            result += str[i];
        }
    }
    cout << "String after removing vowels: " << result << endl;
    return 0;
}