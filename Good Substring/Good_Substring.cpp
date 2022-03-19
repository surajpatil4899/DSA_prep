#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  string s,bad; cin>>s>>bad;
  ll k; cin>>k;
  set<pair<ll,ll>> st;
  for(int i=0;i<s.size();i++){
    ll mod = 1000000007;
    ll hash1 = 0, hash2 = 0;
    ll p1 = 31, p2 = 29;
    ll pow1 = 1, pow2 = 1;
    ll badCount = 0;
    for(int j=i;j<s.size();j++){
        badCount += (bad[s[j]-'a']=='0'?1:0);
        if(badCount>k) break;

        hash1 = (hash1 + (s[j]-'a'+1)*pow1)%mod;
        hash2 = (hash2 + (s[j]-'a'+1)*pow2)%mod;

        pow1 = (pow1*p1)%mod;
        pow2 = (pow2*p2)%mod;

        st.insert(make_pair(hash1,hash2));
    }
  }

  cout<<st.size()<<endl;
}