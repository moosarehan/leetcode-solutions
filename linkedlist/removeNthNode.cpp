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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
        {
            cout<<"ll is empty "<<endl;
            return NULL;
        }
        
        //LETS COUNT THE LENGTH OF LINKED LIST
        int len=0;
        ListNode*current=head;
        while(current!=NULL)
        {
            current=current->next;
            len++;

        }
        if(n==len)
        {
            ListNode*temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        int delnodecount=(len-n)+1;
        int count=1;
        current=head;
        ListNode*prev=head;
        while(count<delnodecount)
        {
            prev=current;
            current=current->next;
             count++;
        }
       prev->next=current->next;
       delete current;
       current=NULL;
        return head;
       
    }
};