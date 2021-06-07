/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* del) {
        del->val=del->next->val;
       ListNode* temp= del->next;
       del->next=del->next->next;
       delete(temp);
    }
};
