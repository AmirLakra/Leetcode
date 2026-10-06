class Solution {
public:
    map<int, vector<pair<int, int>>> mp;

    void solve(TreeNode* root, int row, int col) {
        if (root == NULL)
            return;

        mp[col].push_back({row, root->val});

        solve(root->left, row + 1, col - 1);
        solve(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root, 0, 0);

        vector<vector<int>> ans;

        for (auto &it : mp) {
            vector<pair<int, int>> v = it.second;

            // Sort by row, then value
            sort(v.begin(), v.end());

            vector<int> temp;

            for (auto &p : v) {
                temp.push_back(p.second);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};