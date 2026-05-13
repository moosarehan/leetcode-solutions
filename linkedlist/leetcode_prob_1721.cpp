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
        if(head==NULL)
        {
            return head;
        }
        if(head->next==NULL)
        {
            return head;
        }
        int count=1;
        int len=1;
        ListNode*curr=head;
        ListNode*after=head;
        while(curr->next!=NULL)
        {
            curr=curr->next;
            len++;
        }
        int nthnode=(len-k)+1;
        curr=head;
        while(count<k)
        {
            curr=curr->next;
            count++;
        }
        count=1;
        while(count<nthnode)
        {
            after=after->next;
            count++;
        }
        if(curr==after)
        {
            cout<<"NO SWAPPING "<<endl;
            return head;
        }
        int swap=curr->val;
        curr->val=after->val;
        after->val=swap;
        return head;
        
    }
};