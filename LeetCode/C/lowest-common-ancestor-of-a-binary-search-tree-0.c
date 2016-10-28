/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* findLowestCommonAncestor(struct TreeNode* curr, struct TreeNode* left, struct TreeNode* right) {
    if (left->val <= curr-> val && curr->val <= right->val) {
        return curr;
    }

    if (right->val < curr->val) {
        return findLowestCommonAncestor(curr->left, left, right);
    }
    return findLowestCommonAncestor(curr->right, left, right);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (p->val < q->val) return findLowestCommonAncestor(root, p, q);
    return findLowestCommonAncestor(root, q, p);
}
