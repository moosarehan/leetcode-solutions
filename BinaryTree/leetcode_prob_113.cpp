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
  void DFS(vector<vector<int>>&result,vector<int>path,int totalsum,int target,TreeNode*root)
  {
          if(root==NULL)
          {
            return;
          }
          totalsum=totalsum+root->val;
          path.push_back(root->val);
          if(root->left==NULL&&root->right==NULL)
          {
            if(totalsum==target)
            {
               result.push_back(path);
            }

          }
          DFS(result,path,totalsum,target,root->left);
           DFS(result,path,totalsum,target,root->right);
  }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         vector<vector<int>> result; 
         vector<int>paths;
         int totalpathsum=0;
         DFS(result,paths,totalpathsum,targetSum,root);
         return result;


    }
};