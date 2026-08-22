class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = 0 , r = 0;
        int left_sum = 0 ;
        for(int i = 0 ; i < k ; i++){
            left_sum = left_sum + cardPoints[i];
        }
        int max_sum = left_sum;
        int right_sum = 0;
        int right_index = n-1;
        for(int i = k-1 ; i >= 0 ; i--){
            right_sum = right_sum + cardPoints[right_index];
            left_sum = left_sum - cardPoints[i];
            int ans = right_sum + left_sum;
            max_sum = max(max_sum , ans);
            right_index--;
        }
        return max_sum;
    }
};