class Solution {
public:
    int m = 1337;
        
   int binaryExpIter(int a,long long b){
	int ans = 1;
	while(b){
		if(b&1){
			ans = (ans*1LL*a)%m;
		}
		a = (a*1LL*a)%m;
		b >>= 1;
	}

	return ans;
}
    int superPow(int a, vector<int>& b) {
        
         long long num=0;
        for(auto k:b){
            num=((num*10)+k)%1140;//1140 is the etf value of 1337
        }
        return binaryExpIter(a, num);
    }
};