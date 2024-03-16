#include <iostream>
#include <vector>
using namespace std;
// Time Complexity:- O(n)
// Space Complexity:- O(1)
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    // Cyclic sort
    for (int i = 0; i < n; i++) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    // Find the first missing positive integer
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    // All positive integers from 1 to n are present, return n + 1
    return n + 1;
}

int main() {
    // Example usage
    vector<int> nums = {3, 4, -1, 1};
    cout << "First missing positive integer: " << firstMissingPositive(nums) << endl;
    return 0;
}
