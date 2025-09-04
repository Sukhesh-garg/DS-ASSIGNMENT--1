#include <iostream>
using namespace std;
void duplicateTwos(int arr[100], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 2)
        {
            count++;
        }
    }
    int ending = size - 1 + count;
    if (ending >= 100)
    {
        ending = 99;
    }

    for (int i = size - 1; i >= 0 && ending >= 0; i--)
    {
        if (arr[i] == 2)
        {
            if (ending < 100)
            {
                arr[ending] = 2;
                ending--;
            }
            if (ending < 100)
            {
                arr[ending] = 2;
                ending--;
            }
        }
        else
        {
            if (ending < 100)
            {
                arr[ending] = arr[i];
                ending--;
            }
        }
    }
}

int main()
{
    int arr[100] = {1, 2, 3, 2, 4};
    int size = 5;
    duplicateTwos(arr, size);

    for (int i = 0; i < size + size; i++)
    {
        if (arr[i] != 0 || i < size)
        {
            cout << arr[i] << " ";
        }
    }
    cout << "\n";
    return 0;
}