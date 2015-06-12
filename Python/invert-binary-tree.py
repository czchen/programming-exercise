# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    # @param {TreeNode} root
    # @return {TreeNode}
    def invertTree(self, root):
        if root is None:
            return root

        left = root.left
        right = root.right

        root.left = self.invertTree(right)
        root.right = self.invertTree(left)

        return root
