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
        if(head==NULL)
        {
            return NULL;
        }
        if(head->next==NULL)
        {
            return head;
        }
        ListNode*current=head;
        ListNode*after=head->next;
        while(1)
        {
            int t=current->val;
            current->val=after->val;
            after->val=t;
            if(after->next==NULL||after->next->next==NULL)
            {
                break;
            }
            after=after->next->next;
            current=current->next->next;
        }
        return head;

   }
};