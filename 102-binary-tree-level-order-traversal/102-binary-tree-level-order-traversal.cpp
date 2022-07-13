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
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>>arr;
        if(root==nullptr)return arr;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>ans;
            int n=q.size();
            
            for(int i=0;i<n;i++){
                
                TreeNode*cur=q.front();
                q.pop();
                if(cur->left)q.push(cur->left);
                
                if(cur->right)q.push(cur->right);
                
                ans.push_back(cur->val);
            }
            arr.push_back(ans);
        }
        return arr;
    }
};