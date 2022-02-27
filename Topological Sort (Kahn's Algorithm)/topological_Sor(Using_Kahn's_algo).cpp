class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(V, 0);
	    for(int i=0;i<V;i++){
	        for(int child: adj[i])
	        indegree[child]++;
	    }
	  queue<int> q;
	  vector<int> ans;
	  for(int i=0;i<V;i++){
	      if(indegree[i]==0) q.push(i);
	  }
	  
	  while(!q.empty()){
	      int curr = q.front();
	      q.pop();
	      for(auto a:adj[curr]){
	          indegree[a]-=1;
	          if(indegree[a]==0) q.push(a);
	      }
	      ans.push_back(curr);
	  }
	  
	  return ans;
	}
};