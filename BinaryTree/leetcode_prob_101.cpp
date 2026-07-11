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
   bool twins(TreeNode*root1,TreeNode*root2)
   {
    if(root1==NULL&&root2==NULL)
    {
        return true;
    }
    if(root1!=NULL&&root2==NULL||root2!=NULL&&root1==NULL)
    {
        return false;
    }
      if(root1->val==root2->val)
     {
        return twins(root1->left,root2->right)&&twins(root1->right,root2->left);
     } 
     return false;
     
   }
    bool isSymmetric(TreeNode* root) {
        bool symmetry=twins(root,root);
        return symmetry==true;
    }
};