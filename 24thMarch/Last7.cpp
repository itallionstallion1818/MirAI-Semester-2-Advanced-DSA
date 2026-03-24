#include <iostream>
using namespace std;

// Recursive function to find the last occurrence of 7
int findLast7(int *arr, int n) {
    // Base Case: If index reaches -1, 7 is not found
    if (n==0) {
        return -1;
    }
    // Check if current element is 7
    if (arr[n-1] == 7) {
        return n-1;
    }
    // Recursive call for the previous index
    return findLast7(arr, n-1);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        return 0;
    }

    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }

    // Start searching from the last index (n-1)
    int result = findLast7(arr, n);

    if (result != -1) {
        cout << "Last occurrence of 7 is at index: " << result << endl;
    } else {
        cout << "7 is not present in the array." << endl;
    }

    delete[] arr;
    return 0;
}