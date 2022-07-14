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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i =0;i<inorder.size();i++)
            mp[inorder[i]] = i;
        TreeNode * root = func(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
    
    TreeNode *func(vector<int>& preorder,int prstart,int prend,vector<int>& inorder,int instart,int 
                  inend,unordered_map<int,int>&mp){
        
        //Base case
        if(prstart>prend || instart>inend)  return NULL;
        TreeNode* root = new TreeNode(preorder[prstart]);
        
        //Pointers to Subsequent ROOT and Number of left numbers to root
        int inRoot = mp[root->val];
        int numsLeft = inRoot - instart;
        
        root->left = func(preorder,prstart+1,prstart+numsLeft,inorder,instart,inRoot-1,mp);
        root->right = func(preorder,prstart+numsLeft+1,prend,inorder,inRoot+1,inend,mp);
        
        return root;
        
    }
    
    
};