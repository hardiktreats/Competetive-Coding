class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val){
        if(root==NULL){
            return NULL;
        }
        TreeNode* temp=root;
        if(temp->val==val){
            return temp;
        }
        else if(temp->val>val){
            return searchBST(temp->left,val);
        }
        else{
            return searchBST(temp->right,val);
        }
        return temp;
    }
};