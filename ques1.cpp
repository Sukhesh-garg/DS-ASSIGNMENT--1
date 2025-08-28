#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}
int main()
{
    int arr[7] = {3, 10, 15, 18, 66, 78, 89};
    int n = 7;
    int target;
    cout << "Enter element to search: ";
    cin >> target;
    cout << "Linear Search Result: ";
    int result1 = linearSearch(arr, n, target);
    if (result1 != -1)
        cout << "Element found at index " << result1 << endl;
    else
        cout << "Not found" << endl;
    cout << "Binary Search Result: ";
    int result2 = binarySearch(arr, n, target);
    if (result2 != -1)
        cout << "Element found at index " << result2 << endl;
    else
        cout << "Not found" << endl;
    return 0;
}