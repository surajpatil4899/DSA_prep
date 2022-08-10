#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,m;
vector<int> g[N];
vector<int> vis(N, 0);
vector<int> color(N, 0);




bool dfs(int i,int c,int par){
    vis[i] = true;
    color[i] = c;

	for(auto child: g[i]){
		if(child == par) continue;

		if(color[child] == 0)
		if(!dfs(child, color[i]^3,i))
			return false;

		if(color[i] == color[child]) return false;
	}

	return true;
}

bool color_all(){

   for(int i=1;i<=n;i++){
   	   if(!vis[i])
   	   	if(!dfs(i,1,-1)) return false;
   }
  
  return true;
}

int main(){
	 
	 cin>>n>>m;
      
      for(int i=0;i<m;i++){
             int x,y;
             cin>>x>>y;
             g[x].push_back(y);
             g[y].push_back(x);      		
          }
     
    bool ans = color_all();

    if(!ans) cout << "IMPOSSIBLE";
    else{
    	for(int i=1;i<=n;i++) cout << color[i] << " ";
    }
   
  
}