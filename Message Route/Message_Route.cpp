#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,m;
vector<int> g[N];
vector<int> vis(N, 0);
vector<int> par(N, -1);


void dfs(int i){
	if(vis[i]) return;
	vis[i] = 1;
	for(auto child: g[i]){
		dfs(child);
	}
}

int main(){
	 
	 cin>>n>>m;
      
      for(int i=0;i<m;i++){
             int x,y;
             cin>>x>>y;
             g[x].push_back(y);
             g[y].push_back(x);      		
          }
     
      queue<int> q;
      q.push(1);
      vis[1] = 1;
      int ans = 0;
      int count = INT_MAX;
      while(!q.empty()){
           int v = q.front();
           q.pop();
           for(auto child:g[v]){
           	  if(vis[child]) continue;
           	  vis[child] = 1;
           	  par[child] = v;
           	  q.push(child);
           }

      }
    

    if(par[n]==-1){
    	cout << "IMPOSSIBLE" << endl;
    }else{

        int c = n;
       stack<int> st;
       while(c != -1){
       	  st.push(c);
       	  c = par[c];
       }       
      
      cout << st.size() << endl;

      while(!st.empty()){
      	 cout << st.top() << " ";
      	 st.pop();
      }

    }
   
  
}