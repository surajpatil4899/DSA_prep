class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
//         int count = 0;
//         for(int i=1;i<nums.size();i++){
//           if(nums[i] != nums[count]){
//               count++;
//               nums[count] = nums[i];
//           }
//         }
        
//     return count+1;
        
        
      vector<int> original;
        vector<int> :: iterator it;
        for(it=nums.begin();it!=nums.end();it++){
          int ele = *it;
            if(find(original.begin(),original.end(),ele)!=original.end()){
                nums.erase(it);
                it--;
            }
            else{
                original.push_back(*it);
            }
        }
        
        return nums.size();
    }
    
};