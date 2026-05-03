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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         ListNode*curr=list1;
        if(list1==NULL&&list2==NULL){return NULL;}
        if(list1==NULL&&list2!=NULL)
        {
             list1=list2;
             return list1;
        }
        while(curr->next!=NULL)
        {
            curr=curr->next;

        }
        curr->next=list2;
        curr=list1;
        ListNode*prev=curr;
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
        return list1;
        
    }
};