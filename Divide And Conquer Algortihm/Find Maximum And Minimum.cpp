#include<bits/stdc++.h>
using namespace std;

// Function to find the maximum and minimum values in an array
// Time Complexity: O(n) where n is the number of elements in the array
//   - The function recursively divides the array into halves, and each element is visited once.
// Space Complexity: O(log n) due to the recursive call stack
//   - In the worst case, the maximum depth of the recursion is log n, where n is the number of elements.
void FindMaxMin(int arr[], int low, int high, int& maxVal, int& minVal) {
    // Base case: If the array has only one element
    if (low == high) {
        maxVal = arr[low];
        minVal = arr[high];
    }
    // Base case: If the array has two elements
    else if (low + 1 == high) {
        // Compare the two elements and assign maxVal and minVal accordingly
        if (arr[low] < arr[high]) {
            maxVal = arr[high];
            minVal = arr[low];
        } else {
            maxVal = arr[low];
            minVal = arr[high];
        }
    }
    // Recursive case: If the array has more than two elements
    else {
        // Divide the array into two halves
        int mid = low + (high - low) / 2;

        // Recursively find max and min in the left and right halves
        int leftMax, leftMin, rightMax, rightMin;
        FindMaxMin(arr, low, mid, leftMax, leftMin);
        FindMaxMin(arr, mid + 1, high, rightMax, rightMin);

        // Combine the results from the left and right halves
        maxVal = max(leftMax, rightMax);
        minVal = min(leftMin, rightMin);
    }
}

int main() {
    // Example usage
    int arr[] = {10, 5, 2, 6, 3, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxVal, minVal;
    // Call the function to find max and min values
    FindMaxMin(arr, 0, n - 1, maxVal, minVal);

    // Output the maximum and minimum values
    cout << "Max: " << maxVal << endl;
    cout << "Min: " << minVal << endl;

    return 0;
}
