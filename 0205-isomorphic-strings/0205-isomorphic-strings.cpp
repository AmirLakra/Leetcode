class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char , char> p1 , p2;

        for(int i = 0 ; i < s.size() ; i++){
            // check from 's' to 't'
            if(p1.count(s[i])){
                if(p1[s[i]] != t[i]){
                    return false;
                }
            }
            else{
            p1[s[i]] = t[i];
            }

            //  check from 't' to 's'
            if(p2.count(t[i])){
                if(p2[t[i]] != s[i]){
                    return false;
                }
            }
            else{
                p2[t[i]] = s[i];
            }
        }
        return true;
    }
};