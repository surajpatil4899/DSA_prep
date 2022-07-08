class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int> ans;
       int maxi = a[n-1];
        
        for(int i=n-1;i>=0;i--){
            if(a[i]>=maxi){
                maxi = max(maxi, a[i]);
                ans.push_back(maxi);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
