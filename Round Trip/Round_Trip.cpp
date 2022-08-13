#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,m;
vector<int> g[N];
vector<int> vis(N, 0);
vector<int> parent(N, -1);
int sn,en;



bool dfs(int i,int par){
    vis[i] = true;
    parent[i] = par;

	for(auto child: g[i]){
		if(child == par) continue;
        
        if(vis[child]){
           sn = child;
           en = i;
           return true;
        }
		
		if(!vis[child])
			if(dfs(child,i))
				return true;
		
	}

	return false;
}

bool color_all(){

   for(int i=1;i<=n;i++){
   	   if(!vis[i])
   	   	if(dfs(i,-1)) return true;
   }
  
  return false;
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
    	int tn = en;
    	vector<int> res;
    	res.push_back(en);
    	while(tn != sn){
    		res.push_back(parent[tn]);
    		tn = parent[tn];
    	}
        res.push_back(en);
        cout << res.size() << endl;
        for(int c: res) cout << c << " ";

    }
   
  
}