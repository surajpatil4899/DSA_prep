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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head ,*fast = head ,*curr = head ,*prev = NULL;
        while(fast && fast->next){
            curr = slow;
            slow = slow->next;
            fast = fast->next->next;
            curr->next = prev;
            prev = curr;
        }
        if(fast) slow = slow->next;  //in oddd length case
        while(prev && prev->val==slow->val){
            prev = prev->next;
            slow = slow->next;
        }
        
        return !prev; //used not because in case traversal is not reached end
    }
};