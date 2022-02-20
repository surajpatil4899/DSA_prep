class Solution {
public:
    void dfs(vector<vector<int>>& rooms,vector<bool> &visited,int vertex ){
        
        if(visited[vertex]) return;
        visited[vertex] = true;
        for(int child: rooms[vertex]){
            dfs(rooms,visited,child);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
       vector<bool> visited(n, false);
        
        dfs(rooms,visited,0);
        
        for(int i=0;i<n;i++){
           if(!visited[i]) return false;
        }
        
        return true;
    }
};