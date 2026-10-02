class Solution {
public:
    int maxSum;

    int solve(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int l = max(0, solve(root->left));
        int r = max(0, solve(root->right));

        int currentPath = l + r + root->val;

        maxSum = max(maxSum, currentPath);

        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;

        solve(root);

        return maxSum;
    }
};