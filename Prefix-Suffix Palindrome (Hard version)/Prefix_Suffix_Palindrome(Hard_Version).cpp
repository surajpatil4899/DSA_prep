#include<bits/stdc++.h>
#define ll long long
using namespace std;

int kmp(string s){
    vector<int> lps(s.size(),0);
    int j = 0;
    int i = 1;
    while(i<s.size()){
        if(s[i]==s[j]){
            lps[i] = j+1;
            i++;
            j++;
        }else{
            if(j==0)i++;
            else j = lps[j-1];
        }
    }

    return lps[s.size()-1];
}

int lps(string s){
    string t = s + "?";
    reverse(s.begin(),s.end());
    t += s;
    return kmp(t);
}

int main()
{
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    int n = s.size();
    int l = 0;
    for(int i=0,j=n-1;i<j;i++,j--){
        if(s[i]==s[j]) l++;
        else break;
    }

    string rem = s.substr(l,n-2*l);
    string ans = s.substr(0,l);
    if(rem.size()){
       int pre = lps(rem);
       reverse(rem.begin(),rem.end());
       int suf = lps(rem);
       if(pre>suf){
         reverse(rem.begin(),rem.end());
         ans += rem.substr(0,pre);
       }else ans += rem.substr(0,suf);
    }
    ans += s.substr(n-l,l);
    cout<<ans<<endl;
  }
 
}