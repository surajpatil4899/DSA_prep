#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n,m,k;
	cin >> n >> m >> k;
	vector<int> ds(n);
	vector<int> as(m);
	for(int i=0;i<n;i++)cin>>ds[i];
	for(int i=0;i<m;i++)cin>>as[i];
	
	sort(as.begin(), as.end());
	sort(ds.begin(), ds.end());
	
	int ans = 0;
	int i = 0, j = 0;
	while(i<n){
	    while(j<m && as[j]<ds[i]-k) j++;
	    if(abs(as[j]-ds[i]) <= k){
	        ans++;
	        i++;
	        j++;
	    }else i++;
	   
	}
	
	cout << ans << endl;
	return 0;
}
