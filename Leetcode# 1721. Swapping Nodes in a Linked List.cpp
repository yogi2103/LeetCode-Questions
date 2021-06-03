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
    ListNode* swapNodes(ListNode* head, int k) {
        int count=1;
        ListNode* curr1=head;
        ListNode* curr2=head;
        ListNode* temp=head;
        while(count<k){
            temp=temp->next;
            curr1=curr1->next;
            count++;
        }
        
        while(curr1->next){
            curr1=curr1->next;
            curr2=curr2->next;
        }
        
        swap(temp->val,curr2->val);
        return head;
    }
};
