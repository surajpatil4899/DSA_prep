class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m+n-1;
        int l = m-1;
        int r = n-1;
        while(l>=0 && r>=0){
            if(nums1[l]>=nums2[r]){
                nums1[i] = nums1[l];
                l--;
                i--;
            }
            else{
                nums1[i] = nums2[r];
                r--;
                i--;
            }
      }
        while(r>=0){
            nums1[i] = nums2[r];
            r--;
            i--;
        }
        
    }
};