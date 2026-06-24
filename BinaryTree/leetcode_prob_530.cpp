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
   void dfs(TreeNode*root,long long int &ans,long long int &prev)
   {
      if(root==NULL)
      {
        return;
      }
      dfs(root->left,ans,prev);
     long long  int diff=abs(root->val-prev);
      if(diff<ans)
      {
        ans=diff;
      }
      prev=root->val;
      dfs(root->right,ans,prev);
   }
    int getMinimumDifference(TreeNode* root) {
       long long int mindiff=INT_MAX;
       long long int prev=INT_MIN;
        dfs(root,mindiff,prev);
        return mindiff;
    }
};