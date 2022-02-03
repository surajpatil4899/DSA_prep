class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int row = matrix.size();
      
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j], matrix[j][i]); // gives transpose of matrix
            }
        }
        
        for(int i=0;i<row;i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};