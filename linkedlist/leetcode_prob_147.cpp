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
    ListNode* insertionSortList(ListNode* head) {
        
        ListNode*curr=head;
         while(curr->next!=NULL)
        {
              ListNode*prev=curr->next;

            while(prev)
            {
                if(curr->val>prev->val)
                {
                    int t=curr->val;
                    curr->val=prev->val;
                    prev->val=t;
                }
                prev=prev->next;
            }
            curr=curr->next;
        }
        return head;
    }
};