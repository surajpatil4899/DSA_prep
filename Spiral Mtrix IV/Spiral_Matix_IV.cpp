/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m, vector<int>(n));
        
        vector<int> num;
        
        while(head){
              num.push_back(head->val);
            head = head->next;
        }
        
        int s = 0;
        
         int l,r,t,d,p;
        l = 0;
        r = n-1;
        t = 0;
        d = m-1;
        p = 0;
        
        while(t<=d && l<=r){
            if(p==0){
                for(int i=l;i<=r;i++) mat[t][i] = s<num.size() ? num[s++] : -1;
                t++;
            }else if(p==1){
                for(int i=t;i<=d;i++) mat[i][r] = s<num.size() ? num[s++] : -1;
                r--;
            }else if(p==2){
                for(int i = r;i>=l;i--) mat[d][i] = s<num.size() ? num[s++] : -1;
                d--;
            }else if(p==3){
                for(int i=d;i>=t;i--) mat[i][l] = s<num.size() ? num[s++] : -1;
                l++;
            }
            p = (p+1)%4;
        }
        
        return mat;
    }
};