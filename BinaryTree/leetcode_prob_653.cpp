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
   void Inorder(TreeNode*root,vector<int>&ans)
   {
    if(root==NULL)
    {
        return;
    }
    Inorder(root->left,ans);
    ans.push_back(root->val);
    Inorder(root->right,ans);
   }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        Inorder(root,inorder);
        int left=0;
        int right=inorder.size()-1;
        int currsum=0;
        while(left<right)
        {
            currsum=inorder[left]+inorder[right];
            if(currsum<k)
            {
                left++;
            }
            else if(currsum>k)
            {
                right--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};