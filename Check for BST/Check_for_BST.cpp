class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool solve(Node* root, int max, int min){
        if(!root) return true;
        if(root->data >= max || root->data <= min) return false;
        return solve(root->left,root->data,min) && solve(root->right,max,root->data);
    }
    bool isBST(Node* root) 
    {
       return solve(root, INT_MAX, INT_MIN); 
    }
};

