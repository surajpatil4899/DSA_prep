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
    int solve(TreeNode* root){
        if(!root) return 0;
        
        int l = solve(root->left);
        int r = solve(root->right);
        
        if(l==-1 || r==-1) return -1;
        if(abs(l-r)>1) return -1;
        
        return max(l,r) + 1;
        
    }
    bool isBalanced(TreeNode* root) {
        return solve(root) != -1;
    }
};