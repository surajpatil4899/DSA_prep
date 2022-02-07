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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
         ListNode* linkSaver = head->next->next;
        ListNode* secondNode = head->next;
        
        head->next = linkSaver;
        secondNode->next = head;
        head->next = swapPairs(linkSaver);
        
        return secondNode;
    }
};