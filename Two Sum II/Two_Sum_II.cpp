class Solution {
public:
vector<int> twoSum(vector<int>& numbers, int target) {
      // vector<int> vec;  
       
        
         int curr = 0;
        int i = 0;
        int j = numbers.size()-1;
        
        while(i<j){
            int curr = numbers[i]+numbers[j];
           if(curr>target)
           {
               j--;
           }
           else if(curr<target)
           {
               i++;
           }
            else if(curr == target){
               return {i+1, j+1};
               
            }
            
        }
        
        return {};
    }
};