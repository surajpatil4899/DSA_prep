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
void insertAtTail(ListNode* &head,ListNode* &tail,int data){
ListNode* temp=new ListNode(data);
if(head==NULL){
head=temp;
tail=temp;
return;
}else{
tail->next=temp;
tail=temp;
}
}
public:
ListNode* removeElements(ListNode* head, int val) {

    if(head==NULL)
        return NULL;
    ListNode* newhead=NULL;
    ListNode* newtail=NULL;
    ListNode* temp=head;
    
    while(temp){
        if(temp->val!=val){
            insertAtTail(newhead,newtail,temp->val);
        }
        temp=temp->next;
    }
    return newhead;
}
};