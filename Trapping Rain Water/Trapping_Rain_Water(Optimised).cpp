class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int left = 0; 
        int right = n-1;
        int ans = 0;
        int leftM = 0, rightM = 0;
        
        while(left<=right){
            
            if(height[left]<=height[right]){
                if(height[left]>=leftM) leftM = height[left];
                else ans += leftM - height[left];
                left++;
            }
            else{
                if(height[right]>=rightM) rightM = height[right];
                else ans += rightM - height[right];
                right--;
            }
        }
        
        return ans;
    }
};