class Solution {
public:
    int fillCups(vector<int>& a) {
        sort(a.begin(), a.end());
          int x=a[0];
      int y=a[1];
      int z=a[2];
      int sum=x+y+z;
      if(x+y>z) return sum/2+sum%2;
      if(x==0 && y==0) return z;
      else return z;
    }
};