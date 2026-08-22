class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        int l = 0, r = 0;
        int ans = 0;
        int result = 0;
        int zeros = 0;

        while (r < n) {

            ans += nums[r];

            while (l < r && ans > goal) {
                ans -= nums[l];
                l++;
                zeros = 0;
            }

            if (ans == goal) {
                while (l < r && nums[l] == 0) {
                    zeros++;
                    l++;
                }

                result += zeros + 1;
            }

            r++;
        }

        return result;
    }
};