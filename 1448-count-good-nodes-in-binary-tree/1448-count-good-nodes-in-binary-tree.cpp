class Solution {
public:
    int goodNodes(TreeNode* root,int maz=INT_MIN) {
        if(root==NULL)
        return 0;
        int count =0;
        if(maz<=root->val)
        {
            maz = root->val;
            count+=1;
        }   
        return count+=goodNodes(root->right,maz)+goodNodes(root->left,maz);
    }
};