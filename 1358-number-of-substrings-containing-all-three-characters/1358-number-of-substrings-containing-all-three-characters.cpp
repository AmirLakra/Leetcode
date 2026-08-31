class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0 , r = 0;
        int result = 0;
        vector<int> mp(3,0);
        while(r < n){
            char ch = s[r];
            mp[ch - 'a']++;
            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0){
                result += (n-r);

                mp[s[l] - 'a']--;
                l++;
            }
            r++;
        }
        return result;
    }
};