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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* smallhead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return smallhead;
        
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* curr=head;
        ListNode* back=reverse(slow);
        
        while(curr && back){
            if(curr->val!=back->val){
                return false;
            }
            curr=curr->next;
            back=back->next;
        }
        return true;
    }
};
