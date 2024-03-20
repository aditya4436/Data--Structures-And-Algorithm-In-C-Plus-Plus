#include <vector>
using namespace std;

void combinationSumHelper(int start, int k, int n, vector<int> &temp, vector<vector<int>> &ans) {
    // Base case: If both k and n are zero, add the current combination to the result
    if (n == 0 && k == 0) {
        ans.push_back(temp);
        return;
    }

    // Base case: If start exceeds 9, k becomes zero, or n becomes zero, return
    if (start > 9 || k == 0 || n == 0) {
        return;
    }
    
    // Pick the current number and recurse
    temp.push_back(start);
    combinationSumHelper(start + 1, k - 1, n - start, temp, ans);

    // Don't pick the current number and recurse
    temp.pop_back();
    combinationSumHelper(start + 1, k, n, temp, ans);
}

// Function to find all combinations of k numbers that sum up to n
// Time Complexity: O(2^k) in the worst case
//   - Each element can be either included or excluded in the combination, leading to 2 choices at each step
//   - We explore all possible combinations, which results in exponential time complexity
// Space Complexity: O(k) for recursive stack space + O(k * x) for the result, where x is the average size of the combinations
//   - The recursive stack space is O(k) as the maximum depth of recursion is k
//   - Each combination can have at most k elements, so the space for the result is O(k * x)
vector<vector<int>> combinationSum(int k, int n) {
    vector<int> temp;
    vector<vector<int>> ans;
    combinationSumHelper(1, k, n, temp, ans);
    return ans;
}

int main() {
    // Example usage:
    int k = 3, n = 7;
    vector<vector<int>> result = combinationSum(k, n);
    // Print the result
    for (const vector<int>& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
