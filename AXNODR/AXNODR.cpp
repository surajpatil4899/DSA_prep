#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
	   long long n;
	   cin>>n;
       n -= 1;
	   if(n%4 == 0){
	   	 long long group = n/4;
         long long ans = (3+(4*(group)))-2;
         cout<<ans<<endl;
	   }else{
	   	 long long g = (n/4) + 1;
	   	 long long ge = n%4;
         if(ge==1 || ge==2){
         	cout<<3<<endl;
         }else{
         	long long res = 3+(4*(g));
            cout<<res<<endl;
         }
	   }
	}

}