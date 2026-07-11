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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>levelorder;
        if(root!=NULL)
        {
            q.push(root);
        }
        while(!q.empty())
        {
            int n=q.size();
            vector<int>ans;
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
             levelorder.push_back(ans);
            
        }
       
        return levelorder;

    }
};