class Solution {
public:
    void solve(int index, int k, int target, vector<int>& temp, vector<vector<int>>& result) {
        if (target == 0 && temp.size() == k) {
            result.push_back(temp);
            return;
        }

        if (target < 0 || temp.size() >= k) {
            return;
        }

        for (int i = index; i <= 9; i++) {
            if (i > target) {
                break;
            }

            temp.push_back(i);
            solve(i + 1, k, target - i, temp, result);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(1, k, n, temp, result);
        return result;
    }
};