#include <bits/stdc++.h>
using namespace std;

int main() {
 int t;
 cin>>t;
 while(t--){
     int n;
     cin>>n;
     int a[n];
     for(int i=0;i<n;i++) cin>>a[i];
     for(int i=n-2;i>=0;i--){
         a[i] = max(a[i], max(0, a[i+1]-1));
     }
     
     for(int c:a) cout<<(c>0?1:0)<<" ";
     cout<<endl;
 }
	return 0;
}
