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
    int minDepth(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int l=minDepth(root->left);
        int r=minDepth(root->right);
        int minimum=0;
        if(l==0)
        {
         minimum=r;
        }
        else if(r==0)
        {
            minimum=l;
        }
        else
        {
            minimum=min(l,r);
        }
        return(1+minimum);
    }
};