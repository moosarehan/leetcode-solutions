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
      int find(int instart,int inend,int target,vector<int>inorder)
      {
        for(int i=instart;i<=inend;i++)
        {
            if(inorder[i]==target)
            {
                return i;
            }
        }
        return -1;
      }
    TreeNode*solve(int instart,int inend,int index,vector<int>&pre,vector<int>&in)
    {
        if(instart>inend)
        {
            return NULL;
        }
        TreeNode*root=new TreeNode(pre[index]);
        int pos=find(instart,inend,pre[index],in);
        root->left=solve(instart,pos-1,index+1,pre,in);
        root->right=solve(pos+1,inend,index+(pos-instart)+1,pre,in);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       TreeNode*root= solve(0,inorder.size()-1,0,preorder,inorder);
       return root;
    }
};