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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode*current=head;
        int len=0;
        while(current)
        {
            len++;
            current=current->next;
        }
        current=head;
        int arr[len];
        for(int i=0;i<len;i++)
        {
            arr[i]=current->val;
            current=current->next;
        }
        int *ptr=&arr[left-1];
        int *ptr1=&arr[right-1];
        while(ptr<ptr1)
        {
            int swap=*ptr;
            *ptr=*ptr1;
            *ptr1=swap;
             ptr++;
             ptr1--;
        }
        current=head;
        for(int i=0;i<len;i++)
        {
            current->val=arr[i];
            current=current->next;
        }
        return head;

    }
};