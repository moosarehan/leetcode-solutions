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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){return NULL;}
        if(head->next==NULL){return head;}
      int len=0;
      ListNode*curr=head;
      while(curr)
      {
        curr=curr->next;
        len++;
      }
      curr=head;
      int arr[len];
      int i=0;
      while(1)
      {
        arr[i]=curr->val;
        if(curr->next==nullptr||curr->next->next==nullptr)
        {
            break;
        }
        curr=curr->next->next;
        i++;
      }
      i++;
      curr=head->next;
       while(1)
      {
        arr[i]=curr->val;
        if(curr->next==nullptr||curr->next->next==nullptr)
        {
            break;
        }
        curr=curr->next->next;
        i++;
      }
      curr=head;
      for(int i=0;i<len;i++)
      {
        curr->val=arr[i];
        curr=curr->next;
      }
      return head;
    }
};