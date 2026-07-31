#include <vector>
#include <algorithm>

class Solution {
public:
    void backtrack(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current); // Add current subset
        
        for (int i = index; i < nums.size(); i++) {
            // Skip duplicate elements at the same depth
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }
            
            current.push_back(nums[i]);       // Include nums[i]
            backtrack(i + 1, nums, current, result); // Move to next element
            current.pop_back();              // Backtrack (remove nums[i])
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Step 1: Sort to handle duplicates easily
        sort(nums.begin(), nums.end());
        
        // Step 2: Start backtracking
        backtrack(0, nums, current, result);
        
        return result;
    }
};