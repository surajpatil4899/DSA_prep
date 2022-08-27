class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
   int sum=0,a=0,cnt=0;
        for(int i : energy) sum+=i;
        if(sum>= initialEnergy) a = sum-initialEnergy+1;
        for(int i=0;i<size(experience);i++)
        {
            if(experience[i]>=initialExperience) {
                int temp = experience[i]-initialExperience+1;
                cnt+=temp;
                initialExperience+=temp+experience[i];
            }
            else initialExperience+=experience[i];
        }
        return a+cnt;
    }
};