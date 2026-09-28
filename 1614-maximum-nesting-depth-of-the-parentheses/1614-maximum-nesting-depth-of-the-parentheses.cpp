class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int result = 0 ,ans = 0;
        while(n){
            
            if(s[n-1] == '('){
                ans--;
            }
            else if(s[n-1] == ')'){
                ans++;
            }
            result = max(ans , result);
            n--;
        }
        return result;
    }
};