class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin() , nums.end() , 0);
        int min = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            if(min > nums[i]){
                min = nums[i];
            }
        }
        return sum - (n*min);
    }
};