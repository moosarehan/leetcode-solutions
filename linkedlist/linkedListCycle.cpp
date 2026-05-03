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
    bool hasCycle(ListNode *head) {
        if(head==nullptr||head->next==NULL)
        {
            return false;
        }
        ListNode*current=head;
        ListNode*forward=head->next;
        while(forward!=nullptr)
        {
            current=current->next;
            if(forward->next==nullptr)
            {
                 break;
            }
            forward=forward->next->next;
            if(forward==current)
            {
                return true;
            }
        }
        return false;
    }
};