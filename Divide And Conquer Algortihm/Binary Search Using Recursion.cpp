#include<bits/stdc++.h>
using namespace std;

// Binary search function with recursion
// Time Complexity: O(log n) where n is the number of elements in the array
//   - Each recursive call reduces the search space by half.
// Space Complexity: O(log n) due to the recursive call stack
//   - In the worst case, the maximum depth of the recursion is log n.
int RecursiveBinarySearch(int arr[], int low, int high, int x) {
    if (low > high) {
        return -1;  // Element not found
    }
    
    int mid = low + (high - low) / 2;
    
    if (x == arr[mid]) {
        return mid;  // Element found at index mid
    } else if (x < arr[mid]) {
        return RecursiveBinarySearch(arr, low, mid - 1, x);  // Search in the left half
    } else {
        return RecursiveBinarySearch(arr, mid + 1, high, x);  // Search in the right half
    }
}

int main() {
    // Example usage
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    // Call binary search function
    int result = RecursiveBinarySearch(arr, 0, n - 1, target);

    // Output the result
    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array" << endl;
    }

    return 0;
}
