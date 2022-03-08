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
    map<TreeNode*,int> dp;
    int solve(TreeNode* root){
        if(!root) return 0;
        
        if(dp.count(root)) return dp[root];
        
        int including = root->val;
        if(root->left) including += solve(root->left->left) + solve(root->left->right);
        if(root->right) including += solve(root->right->left) + solve(root->right->right);
        
        int excluding = solve(root->left) + solve(root->right);
        
        int ans = max(including,excluding);
        
        return dp[root] = ans;
    }
    int rob(TreeNode* root) {
      return solve(root);
    }
};