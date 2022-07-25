class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
         map<int,int> same_suit;
        map<int,int> same_rank;
        for(int i=0; i<ranks.size(); i++)
        {
            same_suit[suits[i]-'a']++; //storing count of same char
            same_rank[ranks[i]]++; //storing count of same rank
        }
        
        for(int i=0; i<ranks.size(); i++)
        {
			//apply operations as per the condition given 
            if(same_suit[suits[i] - 'a'] > 4) 
                return "Flush";
            
            else if(same_rank[ranks[i]] > 2)
                return "Three of a Kind";
            
            else if(same_rank[ranks[i]] > 1)
                return "Pair";
        }
        
        return "High Card";
    }
};