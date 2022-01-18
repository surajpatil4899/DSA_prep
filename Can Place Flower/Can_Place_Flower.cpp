class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
          bool prev = false; // Whether previous spot was occupied.
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i]) prev = true;
            else {
                if (!prev && (i + 1 == flowerbed.size() || flowerbed[i + 1] == 0)) {
                    n--;
                    prev = true;
                } else {
                    prev = false;
                }
            }
        }
        return n <= 0;
    }
};