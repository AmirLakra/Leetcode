class Solution {
public:
    int longest(string s){
        int n = s.size();
        int l = 0 , r = 0;
        int max_length = 0;
        int hash[256];
        fill(hash, hash+256 , -1);
        while(r < n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]]+1;
                }
            }
            hash[s[r]] = r;
            int len = r-l+1;
            max_length = max(len , max_length);
            r++;
        }
        return max_length;
    }

    int lengthOfLongestSubstring(string s) {
        int ans = longest(s);
        return ans;
    }
};