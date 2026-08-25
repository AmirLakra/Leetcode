class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] % k == 0){
                s.insert(nums[i]);
            }
        }
        int ans = k;
        while(s.contains(ans)){
            ans = ans + k;
        }
        return ans;
    }
};