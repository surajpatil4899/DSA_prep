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
TreeNode* convert(vector<int>& nums,int start,int end){
    if(start>end) return NULL;
    
    int mid = (start+end)/2;
    
    TreeNode* root = new TreeNode();
    root->val = nums[mid];
    
    root->left = convert(nums,start,mid-1);
    root->right = convert(nums,mid+1,end);
    
    return root;
}
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* node = convert(nums,0,nums.size()-1);
        
        return node;
    }    
};