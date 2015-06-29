/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode *left;
    struct TreeNode *right;

    if (!root) {
        return root;
    }

    left = root->left;
    right = root->right;

    root->right = invertTree(left);
    root->left = invertTree(right);

    return root;
}
