class Solution {
public:
     vector<int> ans;
    bool isok(vector<vector<int>>& paths,vector<int> &color,int k,int i){
        for(int child:paths[i]){
            if(color[child]==k) return false;
        }
        return true;
    }
    bool solve(vector<vector<int>>& paths,vector<int> &color,int i,int n,int c){
        if(i==n) return true;
        
        for(int k=1;k<=c;k++){
            if(isok(paths,color,k,i)){
                color[i] = k;
                ans.push_back(k);
                if(solve(paths,color,i+1,n,c)) return true;
                
                color[i] = 0;
                ans.pop_back();
            }
        }
        
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n);
        for(auto a:paths){
            graph[a[0]-1].push_back(a[1]-1);
            graph[a[1]-1].push_back(a[0]-1);
        }
       
        vector<int> color(n+1, 0);
        solve(graph,color,0,n,4);
        
        return ans;
    }
};