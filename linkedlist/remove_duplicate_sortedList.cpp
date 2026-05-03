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
    ListNode* deleteDuplicates(ListNode* head) {
           ListNode* current = head;


while (current!=nullptr&&current->next!=nullptr)
{
    ListNode*prev=current;
    ListNode*after=current->next;
	while (after != nullptr)
	{
		if (current->val == after->val)
		{
			prev->next = after->next;
			delete after;
			after = prev->next;
			
		}
		else
		{
			prev = after;
			after = after->next;
		}
	}
	
	   
		current = current->next;



}
return head;
    }
};