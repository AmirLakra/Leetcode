class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
        return false;

        unordered_map<char,int> p1;

        for(char c : s){
            p1[c]++;
        }
        for(char c : t){
            p1[c]--;

            if(p1[c] < 0)
            return false;
        }
        return true;
    }
};