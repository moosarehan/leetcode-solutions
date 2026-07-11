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
    int height(TreeNode*root,bool &valid)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int l=height(root->left,valid);
        int r=height(root->right,valid);
        int diff=l-r;
        if(diff==0||diff==-1||diff==1)
        {
            if(valid==false){return -1;}
            valid=true;
            
        }
        else
        {
            valid=false;
            
        }
        return 1+max(l,r);

        

    }
    bool isBalanced(TreeNode* root) {
        bool flag=1;
       int s= height(root,flag);
       return flag;
    }
};