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
    bool isPalindrome(ListNode* head) {
    int start=1;
    int end=0;
 ListNode* current = head;
 ListNode* newhead = new ListNode(current->val);
 ListNode* temp = newhead;
 ListNode* curr1 = newhead;
 while (current->next!=NULL)
  {
	curr1 = curr1->next;
	current = current->next;
	curr1 = new ListNode(current->val);
	newhead->next = curr1;
	newhead = curr1;
    end++;
 }
 newhead = temp;
 current=head;//NOW REVERSE THE COPIED LINK LIST
 ListNode* prev = NULL;
while (current != NULL)
{
	ListNode* forward = current->next;
	current->next = prev;
		prev = current;
		current = forward;
}
head = prev;
current = head;
ListNode* newhead1 = newhead;
while (start <= end)
	{
if (newhead1->val != current->val)
{
	return false;
}
start++;
end--;
newhead1 = newhead1->next;
current = current->next;
	}
	return true;
    }
};