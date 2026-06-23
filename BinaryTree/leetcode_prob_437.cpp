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
void dfs(TreeNode*root,long long int sum,int target,int &totalpaths)
{
    if(root==NULL)
    {
        return ;
    }
    sum+=root->val;
    if(sum==target){
       totalpaths++;
    }
    dfs(root->left,sum,target,totalpaths);
    dfs(root->right,sum,target,totalpaths);
}
    int pathSum(TreeNode* root, int targetSum) {
        queue<TreeNode*>q;
        q.push(root);
         if(q.front()==NULL){return 0;}
        int totalpath=0;
        while(!q.empty())
        {
           long long int sum=0;
            TreeNode*temp=q.front();
            q.pop();
            dfs(temp,sum,targetSum,totalpath);
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }


        }
        return totalpath;
    }
};