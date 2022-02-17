class Solution{
public:
      int dp[101][101];
    
    int solve(vector<int> &v,int i,int j){
        if(i>=j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int min = INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp = solve(v,i,k) + solve(v,k+1,j) + (v[i-1]*v[k]*v[j]);
            if(temp<min) min = temp;
        }
        
        return dp[i][j] = min;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp, -1, sizeof(dp));
        vector<int> v(arr, arr+N);
        return solve(v,1,N-1);
    }
};