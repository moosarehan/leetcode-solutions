/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        queue<TreeNode*>parents;
        q.push(root);
         bool flag=true;
        while(!q.empty())
        {
            
            int n=q.size();
            TreeNode*found1=NULL;
           TreeNode*found2=NULL;
            for(int i=0;i<n;i++)
            {
                TreeNode*temp=q.front();
                if(temp->left!=NULL){q.push(temp->left);}
                if(temp->right!=NULL){q.push(temp->right);}
                parents.push(temp);
                q.pop();
            }
            n=q.size();
               queue<TreeNode*>temp1=q;
            for(int i=0;i<n;i++)
            {
             
                TreeNode*temp=temp1.front();
                if(temp->val==x)
                {
                    found1=new TreeNode();
                     
                }
                 if(temp->val==y)
                {
                    found2=new TreeNode();
                     
                }
                 
                temp1.pop();
            }
            
            if(found1!=NULL&&found2!=NULL)
            {
                //means on same level
                //now check parent
                while(!parents.empty())
                {
                    TreeNode*check=parents.front();
                    if(check->left!=NULL&&check->right!=NULL)
                    {
                           if ((check->left->val == x && check->right->val == y) || 
                             (check->left->val == y && check->right->val == x)) 
                             {
                             flag = false;  // x and y are siblings, not cousins
                                
                              }
                        else
                        {
                            flag= true;
                           
                           
                        }
                     
                    }
                    parents.pop();
                }

            }
            else
            {
                //level was diff just return 
                if(found1==NULL&&found2==NULL)
                {
                      while(!parents.empty())
                      {
                        parents.pop();
                      }
                }
                else
               {
                flag=false;
               }
            }
        }
       return flag;
    }
};