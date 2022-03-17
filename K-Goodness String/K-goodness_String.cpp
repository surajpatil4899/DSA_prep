
#include <bits/stdc++.h>

using namespace std;

int main ()
{
 int t = 0;
 cin >> t;
 int tc = 0;
    while (t--)
    {
      tc += 1;
      int n,k;
      cin>>n>>k;
      string s;
      cin>>s;
      int count = 0;
      int lo = 0, hi = n-1;
      while(lo<hi){
        if(s[lo] != s[hi]) count++;
        lo++;
        hi--;
      }
      if(count==k){
        cout<<"Case"<<" "<<"#"<<tc<<": "<<0<<endl;
      }else if(count<k) cout<<"Case"<<" "<<"#"<<tc<<": "<<k-count<<endl;
      else cout<<"Case"<<" "<<"#"<<tc<<": "<<count-k<<endl;
    }

 return 0;
}