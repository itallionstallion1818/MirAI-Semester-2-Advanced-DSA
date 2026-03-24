#include <iostream>
using namespace std;

// Recursive function to find the first occurrence of 7
int findFirst7(int *arr, int n, int index) {
    // Base Case: If index reaches n, 7 is not found
    if (index == n) {
        return -1;
    }
    // Check if current element is 7
    if (arr[index] == 7) {
        return index;
    }
    // Recursive call for the next index
    return findFirst7(arr, n, index + 1);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }

    int result = findFirst7(arr, n, 0);

    if (result != -1) {
        cout << "First occurrence of 7 is at index: " << result << endl;
    } else {
        cout << "7 is not present in the array." << endl;
    }

    delete[] arr;
    return 0;
}