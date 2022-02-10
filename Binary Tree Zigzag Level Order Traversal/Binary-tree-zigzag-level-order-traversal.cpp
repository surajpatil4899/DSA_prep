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
    int flag = 0;
    void zigZag(TreeNode* root){
        if(root==NULL) return;
        Q.push(root);
        while(!Q.empty()){
         vector<int> ele;
            int size = Q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr = Q.front();
                Q.pop();
                if(curr->left != NULL) Q.push(curr->left);
                if(curr->right != NULL) Q.push(curr->right);
                ele.push_back(curr->val);
            } 
           if(flag){
               reverse(ele.begin(), ele.end());
               ans.push_back(ele);
               flag = 0;
           } else{
               ans.push_back(ele);
               flag = 1;
           }
            
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        zigZag(root);
        
        return ans;
    }
};