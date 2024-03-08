#include <vector>
#include <algorithm>
#include <climits>

// Time Complexity: O(n^2) - Two-pointer approach within a nested loop
// Space Complexity: O(1) - Sorting is typically performed in-place
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort the input array
        sort(nums.begin(), nums.end());

        int ans = INT_MAX;  // Initialize the difference to a large value
        int result = 0;     // Store the closest sum found
        int n = nums.size(); // Size of the array

        // Iterate through the array
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;

            // Use two pointers approach to find the closest sum to the target
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                // If the current sum is equal to the target, return it immediately
                if (sum == target) {
                    return sum;
                }
                // Update the result if the absolute difference is smaller than the previous best
                else if (abs(target - sum) < abs(ans)) {
                    ans = sum - target; // Store the difference for comparison
                    result = sum;       // Update the result with the closest sum
                }

                // Move the pointers based on the comparison with the target
                if (sum > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        return result;
    }
};
