class Solution {
public:
    vector<int> ans;
    bool isLeaf(Node *root){
        return (!root->left && !root->right);
    }
    void left(Node *root){
        Node *cur = root->left;
        while(cur){
            if(!isLeaf(cur)) ans.push_back(cur->data);
            if(cur->left)  cur = cur->left;
            else cur = cur->right;
        }
    }
    void leaves(Node *root){
        if(isLeaf(root)) ans.push_back(root->data);
        
        if(root->left) leaves(root->left);
        if(root->right) leaves(root->right);
        
    }
    void right(Node *root){
        Node *cur = root->right;
        vector<int> tmp;
        while(cur){
            if(!isLeaf(cur)) tmp.push_back(cur->data);
            if(cur->right) cur = cur->right;
            else cur = cur->left;
        }
        for(int i=tmp.size()-1;i>=0;i--){
            ans.push_back(tmp[i]);
        }
    }
    vector <int> boundary(Node *root)
    {
        if(!root) return ans; 
        if (!isLeaf(root)) ans.push_back(root -> data);
        left(root);
        leaves(root);
        right(root);
      
        
        return ans;
    }
};