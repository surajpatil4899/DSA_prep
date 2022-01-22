class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = INT_MAX;
        int max_pro = 0;
        for(int i=0;i<prices.size();i++){
            minimum = min(minimum, prices[i]);
            max_pro = max(max_pro, (prices[i] - minimum));
        }
        
      
        
        return max_pro;
    }
};