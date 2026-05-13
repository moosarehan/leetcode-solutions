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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL)
        {
            return nullptr;
        }
        if(head->next==NULL)
        {
            delete head;
            head=NULL;
            return head;
        }
        ListNode*slow=head;
        ListNode*fast=head->next;
        ListNode*prev=head;
        while(fast)
        {
            prev=slow;
            slow=slow->next;
            if(fast->next==NULL)
            {
                break;
            }
            fast=fast->next->next;
        }
        prev->next=slow->next;
        delete slow;
        slow=NULL;
        return head;

    }
};