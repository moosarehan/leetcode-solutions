/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
          Node*curr=head;
          while(curr!=NULL)
          {
            if(curr->child!=NULL)
            {
                Node*forward=curr->next;
                Node*children=curr->child;
                curr->next=children;
                children->prev=curr;
                while(children->next!=NULL)
                {
                    children=children->next;

                }
                children->next=forward;
                if(forward!=NULL)
                forward->prev=children;
                curr->child=NULL;
 
            }
            curr=curr->next;
          }
          return head;
    }
};