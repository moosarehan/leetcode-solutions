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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL)
        {
            return {};
        }
        vector<vector<int>>levels;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>ans;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
              TreeNode*temp=q.front();
              q.pop();
              ans.push_back(temp->val);
              if(temp->left!=NULL)
              {
                q.push(temp->left);
              }
              if(temp->right!=NULL)
              {
                q.push(temp->right);
              }
            }
            levels.push_back(ans);
        }
       reverse(levels.begin(),levels.end());
       return levels;
    }
};