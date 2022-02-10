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
    vector<vector<int>> ans;
    void traverse(TreeNode* root,vector<int> &num,int target){
        if(root==NULL) return;
        
        num.push_back(root->val);
        
        if(root->right==NULL&&root->left==NULL){
            if(root->val==target) ans.push_back(num);
        }
        
        traverse(root->left,num,target-root->val);
        traverse(root->right,num,target-root->val);
        
        num.pop_back(); //backtracking
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> num;
        traverse(root,num,targetSum);
        
        return ans;
    }
};