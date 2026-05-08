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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Reverse the first list (l1)
        ListNode* current = l1;
        ListNode* prev = NULL;
        int len = 0;
        while (current) {
            ListNode* forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
            len++;
        }
        l1 = prev;

        // Reverse the second list (l2)
        current = l2;
        prev = NULL;
        int len2 = 0;
        while (current) {
            ListNode* forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
            len2++;
        }
        l2 = prev;

        // Start summing the reversed lists
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        int sum = 0;
        int carry = 0;
        ListNode* temp = new ListNode;
        ListNode* answer = temp;

        // Add corresponding digits of both lists
        while (curr1 && curr2) {
            sum = carry + curr1->val + curr2->val;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* ans = new ListNode(digit);
            temp->next = ans;
            temp = ans;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        // Continue processing the remaining nodes in the longer list (if any)
        while (curr1) {
            sum = carry + curr1->val;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* ans = new ListNode(digit);
            temp->next = ans;
            temp = ans;
            curr1 = curr1->next;
        }

        while (curr2) {
            sum = carry + curr2->val;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* ans = new ListNode(digit);
            temp->next = ans;
            temp = ans;
            curr2 = curr2->next;
        }

       if (carry > 0) {
            ListNode* ans = new ListNode(carry);
            temp->next = ans;
        }

        // Reverse the result list to restore original order
        ListNode* newhead = answer->next;
        prev = NULL;
        while (newhead) {
            ListNode* forward = newhead->next;
            newhead->next = prev;
            prev = newhead;
            newhead = forward;
        }
        newhead = prev;

        return newhead;
    }
};