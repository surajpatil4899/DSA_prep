#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        long long x;
        cin>>x;
        long long pow2 = x & ~(x-1);
        if(x%2 != 0 || x == pow2) cout<<-1<<endl;
        else cout<<pow2/2<<" "<<x/2<<" "<<(x-pow2)/2<<endl;
    }
	return 0;
}
