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
    int ans = 0;
    void traversal(TreeNode * root,vector<int> graph[],int parent){
        if(root == NULL){
            return;
        }

        if(parent!=-1){
            graph[root->val].push_back(parent);
            graph[parent].push_back(root->val);
        }

        traversal(root->left,graph,root->val);
        traversal(root->right,graph,root->val);
        return;
    } 
    
    void dfs(int curr , vector<int> graph[] , int depth[] , int parent){
        if(parent!=-1) depth[curr] = depth[parent]+1;

        ans = max(ans,depth[curr]);
        for(auto x : graph[curr]){
            if(x!=parent){
                dfs(x,graph,depth,curr);
            }
        }
    }
    
    int amountOfTime(TreeNode* root, int start) {
        int N = 1e5 + 1;
        vector<int> graph[N];
        traversal(root,graph,-1); // making Graph
        int depth[N]; memset(depth,0,sizeof(depth)); // depth calculation
        dfs(start,graph,depth,-1);
        return ans;    
    }
};