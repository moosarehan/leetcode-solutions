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
   void heapify(vector<int>&arr,int ind,int size)
   {
        int large=ind;
        int l=2*ind+1;
        int r=2*ind+2;
        if(l<size&&arr[l]>arr[large])
        {
            large=l;
        }
          if(r<size&&arr[r]>arr[large])
        {
           large=r;
        }
        if(large!=ind)
        {
            swap(arr[ind],arr[large]);
            heapify(arr,large,size);
        }
   }
    void convertmax(vector<int>&val)
    {
        int n=val.size();
        for(int i=n/2-1;i>=0;i--)
        {
             heapify(val,i,n);
              
        }
        for(int i=n-1;i>0;i--)
        {
            swap(val[0],val[i]);
            heapify(val,0,i);
        }
    }
    ListNode* sortList(ListNode* head) {
        vector<int>val;
        ListNode*curr=head;
        while(curr!=NULL)
        {
            val.push_back(curr->val);
            curr=curr->next;
        }
        curr=head;
        convertmax(val);
        for(int i=0;i<val.size();i++)
        {
            curr->val=val[i];
            curr=curr->next;
        }
        return head;

    }
};