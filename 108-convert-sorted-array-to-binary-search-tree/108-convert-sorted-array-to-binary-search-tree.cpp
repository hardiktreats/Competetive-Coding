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
       TreeNode* convertintoBST(vector<int> nums,int left,int right)
{
   //Base Case
    if(left > right) return NULL;
	//find mid
    int mid = left+(right-left)/2;
	//create Node
    TreeNode *node = new TreeNode(nums[mid]);
	//Set tree using recursion
    node->left = convertintoBST(nums,left,mid-1);
	
    node->right = convertintoBST(nums,mid+1,right);
	
    return node;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.size() == 0) return NULL;
    return convertintoBST(nums,0,nums.size()-1);
}
};