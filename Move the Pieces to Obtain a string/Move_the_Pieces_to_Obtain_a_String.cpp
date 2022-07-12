class Solution {
public:
    bool canChange(string start, string target) {
        if(start.size() != target.size()) return false;
        
        int s = 0;
        int t = 0;
        
        while(s < start.size() || t < target.size()){
            while(s < start.size() && start[s]=='_') s++;
            while(t < target.size() && target[t]=='_') t++;
            
            if(s==start.size() && t==target.size()) return true;
            if(s==start.size() || t==target.size() || start[s] != target[t]) return false;
            if(s < start.size() && t < target.size()){
                if(target[t]=='L' && s<t) return false;
                if(target[t]=='R' && s>t) return false;
            }
            s++;
            t++;
        } 
        
        return true;
    }
};