/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        q.push(root);
        if(q.front()==NULL)
        {
            return NULL;
        }
        while(!q.empty())
        {
            int n=q.size();
            vector<Node*>nodes;
            for(int i=0;i<n;i++)
            {
                Node*temp=q.front();
                q.pop();
                nodes.push_back(temp);
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
            }
            for(int i=0;i<nodes.size()-1;i++)
            {
                nodes[i]->next=nodes[i+1];
            }
            nodes.back()->next=NULL;
        }
        return root;
    }
   
};