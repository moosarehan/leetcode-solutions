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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){return NULL;}
        
        ListNode*curr=head;
        ListNode*dummy=new ListNode(head->val);
       ListNode* prev=dummy;
       dummy->next=head;
        while(curr!=NULL)
        {
            if(curr->val==val)
            {
                prev->next=curr->next;
                delete curr;
                curr=prev;
            }
            prev=curr;
            curr=curr->next;
        }
        return dummy->next;
    }
};