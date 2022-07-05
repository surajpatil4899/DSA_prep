class Solution {
public:
    #define ll long long
  const int mod = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forgot) {
       ll day = 2;
        vector<array<ll,3>> persons = {{delay+1,forgot+1,1}};
        while(day<=n){
            while(!persons.empty() && persons[0][1]==day) persons.erase(persons.begin());
            
            ll cnt = 0;
            for(auto &x:persons){
                if(x[0]<=day) cnt+=x[2];
            }
            cnt %= mod;
            
            persons.push_back({day+delay,day+forgot,cnt});
            day++;
        }
        
        ll ans = 0;
        for(auto &x:persons){
            ans += x[2];
            ans %= mod;
        }
        
        return ans;
    }
};