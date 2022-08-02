#include <bits/stdc++.h>
using namespace std;
int n,m;
bool vis[1001][1001];

void dfs(int i,int j){
	if(i < 0 || i >= n || j < 0 || j >= m) return;
	if(vis[i][j]) return;
	vis[i][j] = 1;

     dfs(i+1,j);
     dfs(i-1,j);
     dfs(i,j+1);
     dfs(i,j-1);
    
    return;
}

int main(){
	 
	 cin>>n>>m;
      
      for(int i=0;i<n;i++){
      	for(int j=0;j<m;j++){
      		char c; cin>>c;
      		vis[i][j] = (c=='#');
      	}
      }
     
     int ans = 0;
     for(int i=0;i<n;i++){
     	for(int j=0;j<m;j++){
     		if(!vis[i][j]){
     			dfs(i,j);
     			ans++;
     		}
     	}
     }

     cout << ans;

}