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
bool dfs(TreeNode*root,int target)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->val==target)
    {
        return dfs(root->left,target)&&dfs(root->right,target);
    }
    return false;
}
    bool isUnivalTree(TreeNode* root) {
        int target=root->val;
        return dfs(root,target)==true;

    }
};