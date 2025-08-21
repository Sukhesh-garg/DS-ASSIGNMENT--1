#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void createArray(int arr[], int &size) {
    cout << "Enter the size of the array (max 100): ";
    cin >> size;
    if (size > MAX_SIZE || size <= 0) {
        cout << "enter size within limits." << endl;
        size = 0;
        return;
    }
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void displayArray(int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int &size) {
    if (size >= MAX_SIZE) {
        cout << "Array is full! Cannot insert." << endl;
        return;
    }
    int pos, element;
    cout << "Enter position (0 to " << size << ") to insert: ";
    cin >> pos;
    if (pos < 0 || pos > size) {
        cout << "Invalid position!" << endl;
        return;
    }
    cout << "Enter element to insert: ";
    cin >> element;
    
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = element;
    size++;
    cout << "Element inserted successfully!" << endl;
}

void deleteElement(int arr[], int &size) {
    if (size == 0) {
        cout << "Array is empty! Cannot delete." << endl;
        return;
    }
    int pos;
    cout << "Enter position (0 to " << size-1 << ") to delete: ";
    cin >> pos;
    if (pos < 0 || pos >= size) {
        cout << "Invalid position!" << endl;
        return;
    }
    
    for (int i = pos; i < size-1; i++) {
        arr[i] = arr[i+1];
    }
    size--;
    cout << "Element deleted successfully!" << endl;
}

void linearSearch(int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty! Cannot search." << endl;
        return;
    }
    int element;
    cout << "Enter element to search: ";
    cin >> element;
    
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            cout << "Element found at position: " << i << endl;
            found = 1;
            break;
        }
    }
    if (found == 0) {
        cout << "Element not found in array!" << endl;
    }
}

int main() 
{
    int arr[MAX_SIZE];
    int size = 0;
    int choice;
    
    while (1) {
        cout << "------MENU------" << endl;
        cout << "1. CREATE" << endl;
        cout << "2. DISPLAY" << endl;
        cout << "3. INSERT" << endl;
        cout << "4. DELETE" << endl;
        cout << "5. LINEAR SEARCH" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                createArray(arr, size);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                insertElement(arr, size);
                break;
            case 4:
                deleteElement(arr, size);
                break;
            case 5:
                linearSearch(arr, size);
                break;
            case 6:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    
    return 0;
}