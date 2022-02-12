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
    int sum = 0;
    int maxDepth = 0;
    void maxD(TreeNode* root,int curr){
        if(!root) return;
        if(root != NULL){
            if(curr > maxDepth){
                sum = 0;
                maxDepth = curr;
            }
        }
        if(curr == maxDepth) sum += root->val;
        
        maxD(root->left,curr+1);
        maxD(root->right,curr+1);
  
    }
    int deepestLeavesSum(TreeNode* root) {
      maxD(root,1);
      return sum;
    }
};