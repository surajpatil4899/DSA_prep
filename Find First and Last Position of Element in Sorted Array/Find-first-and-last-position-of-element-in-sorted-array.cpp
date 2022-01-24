class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int index;
        vector<int> v;
        auto it = lower_bound(nums.begin(), nums.end(), target);
      if(it != nums.end()){  
        if(*it == target){
           index = it - nums.begin();
            v.push_back(index);
            for(int i=index+1;i<nums.size();i++){
                if(nums[i]==target)
                    index = i;
                else break;
            }
            v.push_back(index);
        }
          else{
            v.push_back(-1);
            v.push_back(-1);           
        }
      }
        else{
            v.push_back(-1);
            v.push_back(-1);           
        }
        
    return v;
    }
};