#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int positions[N];
int n,cows;

bool canPlaceCows(int mid){
	int last = -1;
	int cows_ct = cows;
	for(int i=0;i<n;i++){
		if(positions[i] - last >= mid || last == -1){
			cows_ct--;
			last = positions[i];
		}
		if(cows_ct==0) break;
	}
	
	return cows_ct==0;
}

int main() {
   int t;
   cin>>t;
   while(t--){
   	cin>>n>>cows;
   	for(int i=0;i<n;i++){
   		cin>>positions[i];
   	}
   	sort(positions, positions+n);
   	
   	int lo = 0, hi = 1e9, mid;
   	while(hi - lo > 1){
   		mid = (hi + lo)/2;
   		if(canPlaceCows(mid)){
   			lo = mid;
   		}else{
   			hi = mid - 1;
   		}
   	}
   	
   	if(canPlaceCows(hi)) cout<<hi<<endl;
   	else cout<<lo<<endl;
   	
   }
	return 0;
}