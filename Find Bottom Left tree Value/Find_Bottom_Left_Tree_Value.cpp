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
    int maxDepth,leftVal;
    void solve(TreeNode* root,int depth){
        if(!root) return;
        
        solve(root->left,depth+1);
        solve(root->right,depth+1);
        
        if(depth>maxDepth){
            maxDepth = depth;
            leftVal = root->val;
        }
        
    }
    int findBottomLeftValue(TreeNode* root) {
        maxDepth = 0;
        
        leftVal = root->val;
        
        int depth = 0;
        solve(root,depth);
        
        return leftVal;
    }
};