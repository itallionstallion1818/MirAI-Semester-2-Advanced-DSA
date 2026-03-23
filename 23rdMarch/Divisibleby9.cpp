#include <iostream>
using namespace std;

// Function to calculate the sum of digits recursively
int sumOfDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + sumOfDigits(n / 10);
}

// Recursive function to check divisibility by 9
bool isDivisibleBy9(int n) {
    // Base cases
    if (n < 10) {
        return (n == 0 || n == 9);
    }
    
    // Recursive step: check the sum of digits
    return isDivisibleBy9(sumOfDigits(n));
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isDivisibleBy9(abs(n))) {
        cout << n << " is divisible by 9." << endl;
    } else {
        cout << n << " is not divisible by 9." << endl;
    }

    return 0;
}
