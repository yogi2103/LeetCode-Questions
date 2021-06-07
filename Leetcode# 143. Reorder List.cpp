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
 
//1) Find the middle point using tortoise and hare method.
//2) Split the linked list into two halves using found middle point in step 1.
//3) Reverse the second half.
//4) Do alternate merge of first and second halves.
//The Time Complexity of this solution is O(n). 
 
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
    
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* curr=head;
        ListNode* back=reverse(slow);
        
        
        while(curr && back && back->next && curr->next){
            ListNode* temp1=curr->next;
            curr->next=back;
            ListNode* temp2=back->next;
            back->next=temp1;
            curr=temp1;
            back=temp2;
        }
    }
};
