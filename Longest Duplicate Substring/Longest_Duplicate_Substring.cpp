class Solution {
public:
 #define p 10000007
vector<int> roll;
    
    bool match(string s,int len,int size,string& ans){
          unordered_map<int,vector<int>> m;
        
        int hash = 0;
        
        for(int i=0;i<size;i++)
         hash = (hash*26 + (s[i]-'a'))%p;
        
        m[hash].push_back(0);
        
        for(int j=size;j<len;j++){
            
            hash = ((hash-roll[size-1]*(s[j-size]-'a'))%p + p)%p;
            hash = (hash*26 + (s[j]-'a'))%p;
            
            if(m.find(hash)!=m.end())
            {
                for(auto start: m[hash])
                {
                    string temp = s.substr(start,size);
                    string curr = s.substr(j-size+1,size);
                    if(temp.compare(curr)==0)
                    {
                        ans = temp;
                        return true;
                    }
                }
            }           
            m[hash].push_back(j-size+1);
        }
        
        return false;
    }
    string longestDupSubstring(string s) {
        
       ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int len = s.size();
        if(len==0) "";
        
        roll.resize(len);
        roll[0] = 1;
        for(int i=1;i<len;i++)
            roll[i] = (roll[i-1]*26)%p;
        
        int lo = 1, hi = len,mid;
        string ans = "", temp;
        while(lo<=hi){
            temp = "";
            mid = (lo+hi)/2;
            bool flag = match(s,len,mid,temp);
            if(flag){
                if(temp.size()>ans.size())
                    ans = temp;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        
        return ans;
    }
};