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
    bool flag = true;
    void zigZag(TreeNode* root){
        if(root==NULL) return;
        Q.push(root);
        while(!Q.empty()){
            int size = Q.size();
           vector<int> ele(size);
            
            for(int i=0;i<size;i++){
                TreeNode* curr = Q.front();
                Q.pop();
                
                int index = (flag) ? i : (size-1-i);
                ele[index] = curr->val;
                if(curr->left != NULL) Q.push(curr->left);
                if(curr->right != NULL) Q.push(curr->right);
                
            } 
               flag = !flag;
               ans.push_back(ele);
          
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        zigZag(root);
        
        return ans;
    }
};