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
    queue<TreeNode*> Q;
    
    void lOrder(TreeNode* root){
        if(root==NULL) return;
        Q.push(root);
        
        while(!Q.empty()){
            int size = Q.size();
                vector<int> ele;
         for(int i=0;i<size;i++){
            TreeNode* curr = Q.front();
             Q.pop();
            if(curr->left != NULL) Q.push(curr->left);
            if(curr->right != NULL) Q.push(curr->right);
             ele.push_back(curr->val);
         } 
          ans.push_back(ele);
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       lOrder(root);
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};