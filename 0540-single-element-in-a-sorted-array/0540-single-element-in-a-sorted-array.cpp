class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq_map;

        for(int i : nums){
            freq_map[i]++;
        }

        for(auto j : freq_map){
            if(j.second == 1){
                return j.first;
            }
        }
        return -1;
    }
};