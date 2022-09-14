/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
        int pseudoPalindromicPaths(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* node, int seen) {
        if (!node) return 0;
        
        seen ^= 1 << (node->val);
        
        if (!node->left && !node->right) {
            return __builtin_popcount(seen) < 2;
        }
        
        return dfs(node->left, seen) + dfs(node->right, seen);
    }
};