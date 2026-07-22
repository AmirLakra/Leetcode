class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char , int> freq;
        for(char c : s){
            freq[c]++;
        }
        vector<pair<char,int>> vec(freq.begin() , freq.end());

        // sort(start_iterator , end_iterator , comperator)
        sort(vec.begin() , vec.end(),
        [] (const pair<char,int>& a, const pair<char,int>& b){
            return a.second > b.second;
        });

        string ans  = "";

        for(auto& a : vec){
            ans += string(a.second , a.first);
        }
        return ans;
    }
};