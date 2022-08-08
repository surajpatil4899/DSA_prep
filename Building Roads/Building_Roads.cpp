#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,m;
vector<int> g[N];
vector<int> vis(N, 0);
vector<int> lead;


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
     
       int count = 0;

       for(int i=1;i<=n;i++){
       	  if(!vis[i]){
       	  	count++;
       	  	lead.push_back(i);
       	  	dfs(i);
       	  }
       }
    

    cout << count - 1 << endl;

    if(count>1){
    	int u = lead[0]; int v;
    	for(int i=1;i<lead.size();i++){
    		v = lead[i];
    		cout << u << " " << v << endl;
    		u = v;
    	}
    }
}