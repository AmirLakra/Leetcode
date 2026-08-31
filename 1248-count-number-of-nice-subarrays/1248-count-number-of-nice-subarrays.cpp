class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int count = 0;
        int result = 0;
        int oddCount = 0;

        while (r < n) {

            if (nums[r] % 2 != 0) {
                oddCount++;
            }

            while (oddCount > k) {
                if (nums[l] % 2 != 0) {
                    oddCount--;
                }
                l++;
            }

            count = 0;
            int temp = l;

            while (temp <= r && nums[temp] % 2 == 0) {
                count++;
                temp++;
            }

            if (oddCount == k) {
                result += count + 1;
            }

            r++;
        }

        return result;
    }
};