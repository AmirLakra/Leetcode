class Solution {
public:
    int get_left_nodes(TreeNode* root) {
        int height = 0;

        while (root != NULL) {
            height++;
            root = root->left;
        }

        return height;
    }

    int get_right_nodes(TreeNode* root) {
        int height = 0;

        while (root != NULL) {
            height++;
            root = root->right;
        }

        return height;
    }

    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int lh = get_left_nodes(root);
        int rh = get_right_nodes(root);

        if (lh == rh) {
            return (1 << lh) - 1;
        }

        return countNodes(root->left)
             + countNodes(root->right) + 1;
    }
};