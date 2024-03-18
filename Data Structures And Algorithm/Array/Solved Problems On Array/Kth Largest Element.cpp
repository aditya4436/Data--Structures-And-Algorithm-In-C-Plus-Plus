#include <iostream>
#include <vector>
using namespace std;

// Time Complexity:- O(n log n)
// Space Comlexity:- O(1) in the worst case O(log n)
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         int n=nums.size();
//         sort(nums.begin(), nums.end());
//         return nums[n-k];
//     }
// };

// Time Complexity:- O(n), in the worst case it is O(n^2).
// Space Complexity:- O(log n), in the worst case it can be O(n).
class Solution {
    // Partition function to rearrange elements based on pivot
    int Partition(vector<int> &nums, int left, int right){
        int pivot = nums[right]; // Choose the rightmost element as pivot
        int i = left - 1; // Initialize the index of the smaller element

        // Iterate through the array from left to right
        for(int j = left; j < right; j++){
            // If current element is greater than or equal to pivot
            if(nums[j] >= pivot){
                // Move smaller element to the left side
                i++;
                swap(nums[i], nums[j]);
            }
        }

        // Move pivot element to its correct position
        swap(nums[i + 1], nums[right]);

        // Return index of pivot element after partitioning
        return (i + 1);
    }

    // Recursive function to find kth largest element using quick select
    int quickSelect(vector<int> &nums, int left, int right, int k){
        if(left == right){ // Base case: subarray contains only one element
            return nums[left]; // Return the element
        }

        // Partition the array and get index of pivot element
        int pivotIndex = Partition(nums, left, right);
        // Calculate rank of pivot element in sorted array
        int rank = pivotIndex - left + 1;

        // If rank of pivot equals k, return pivot element
        if(rank == k){
            return nums[pivotIndex]; 
        }
        // If rank of pivot is less than k, search in right subarray
        else if(rank < k){
            return quickSelect(nums, pivotIndex + 1, right, k - rank);
        }
        // If rank of pivot is greater than k, search in left subarray
        else{
            return quickSelect(nums, left, pivotIndex - 1, k);
        }
    }
public:
    // Public function to find kth largest element in array
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        // Call quick select function with initial parameters
        return quickSelect(nums, 0, n - 1, k);
    }
};

int main() {
    // Example usage
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4}; // Input vector
    int k = 2; // kth largest element to find
    int result = sol.findKthLargest(nums, k); // Call function
    cout << "The " << k << "th largest element is: " << result << endl; // Output result
    return 0;
}
