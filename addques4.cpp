#include <iostream>
using namespace std;
void swap(int arr[100], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sorting(int arr[100], int size)
{
    int first = 0;
    int check = 0;
    int last = size - 1;

    while (check <= last)
    {
        if (arr[check] == 0)
        {
            swap(arr, first, check);
            first++;
            check++;
        }
        else if (arr[check] == 1)
        {
            check++;
        }
        else
        {
            swap(arr, check, last);
            last--;
        }
    }
}

int main()
{
    int arr[100] = {2, 0, 1, 2, 1, 0, 2, 1};
    int size = 8;
    sorting(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}