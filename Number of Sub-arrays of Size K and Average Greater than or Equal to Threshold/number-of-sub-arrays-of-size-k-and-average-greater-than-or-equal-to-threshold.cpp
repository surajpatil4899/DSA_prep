class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        for(int i=0;i<k;i++){
            sum += arr[i];
        }
        int count = (sum/k >= threshold);
        for(int i=k;i<arr.size();i++){
            sum += arr[i] - arr[i-k];
            count += (sum/k >= threshold);
        }
      
        
        return count;
    }
};