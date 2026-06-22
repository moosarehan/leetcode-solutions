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
   void dfs(vector<string>&paths,TreeNode*root,string temp)
   {
         if(root==NULL){return;}
         if(root->left==NULL&&root->right==NULL)
         {
            
            temp+=std::to_string(root->val);
            paths.push_back(temp);
          
         }
         else
         {
              temp=temp+std::to_string(root->val);
              temp+="->";
         }
         dfs(paths,root->left,temp);
         dfs(paths,root->right,temp);
        
   }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>paths;
        string temp="";
        dfs(paths,root,temp);
        return paths;
    }
};