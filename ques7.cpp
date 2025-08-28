#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 1, 3, 4};
    int n = 5, inversions = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                inversions++;
            }
        }
    }
    cout << "Number of inversions =  " << inversions << endl;
    return 0;
}