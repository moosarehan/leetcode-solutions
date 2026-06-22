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
     void dfs(TreeNode*root,int &small,int &k)
     {
        if(root==NULL)
        {
            return;
        }
        dfs(root->left,small,k);
        if(k==0)
        {
           return;
        }
        else
        {
            
            k--;
            small=root->val;
        }
        dfs(root->right,small,k);
     }
    int kthSmallest(TreeNode* root, int k) {
        int small=0;
        dfs(root,small,k);
        return small;
    }
};