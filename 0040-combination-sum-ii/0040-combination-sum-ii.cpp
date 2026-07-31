class Solution {
public:
    void solve(int index, int target, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                break;
            }

            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            temp.push_back(candidates[i]);
            solve(i + 1, target - candidates[i], candidates, temp, result);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        solve(0, target, candidates, temp, result);
        return result;
    }
};