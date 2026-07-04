class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int ans = INT_MAX;

        while(start <= end){
            int mid = start + (end - start)/2;

            // If array is already sorted
            if(nums[start] <= nums[end]){
                ans = min(ans, nums[start]);
                break;
            }

            // Left part is sorted
            if(nums[start] <= nums[mid]){
                ans = min(ans, nums[start]);
                start = mid + 1;
            }
            else{
                // Right part is sorted, min is in left
                ans = min(ans, nums[mid]);
                end = mid - 1;
            }
        }

        return ans;
    }
};