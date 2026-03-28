#include <iostream>
using namespace std;

// Recursive function to perform Binary Search
int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1; // Base Case: Target not found
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        return mid; // Target found
    }

    if (target < arr[mid]) {
        // Search in the left half
        return binarySearch(arr, low, mid - 1, target);
    } else {
        // Search in the right half
        return binarySearch(arr, mid + 1, high, target);
    }
}

int main() {
    int n, target;
    cout << "Enter number of elements (sorted): ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter target to search: ";
    cin >> target;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) cout << "Element found at index: " << result << endl;
    else cout << "Element not found." << endl;

    return 0;
}