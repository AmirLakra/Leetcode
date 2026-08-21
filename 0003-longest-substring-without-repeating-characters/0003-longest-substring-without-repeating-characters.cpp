class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            int hash[256] = {0};
            for(int j = i ; j < n ; j++){
                if(hash[s[j]] == 1){
                    break;
                }
                int length = j-i+1;
                ans = max(ans,length);
                hash[s[j]] = 1;
            } 
        }
        return ans;
    }
};