class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        sort(nums.begin(), nums.end());
        int range = 0;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] - nums[i-1] != 1){
                int start = nums[i-1] + 1;
                int end = nums[i];
                while(start < end){
                    result.push_back(start);
                    start++;
                }
            }
        }
        return result;
    }
};