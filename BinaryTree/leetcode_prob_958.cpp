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
    
    bool isCompleteTree(TreeNode* root) {
       queue<TreeNode*>q;
       if(root->left==NULL&&root->right==NULL){return 1;}
       q.push(root);
       bool flag=true;
       while(!q.empty())
       {
        TreeNode*temp=q.front();

         if(temp->left!=NULL)
         {

            if(flag==false)
            {
                return false;
            }
             q.push(temp->left);
            
         }
         else
         {
            flag=false;
         }
          if(temp->right!=NULL)
          {
            if(flag==false)
            {
                return false;
            }
             q.push(temp->right);
          }
          else
          {
            flag=false;
          }
          
          q.pop();
         
       }
       return true;
    }
};