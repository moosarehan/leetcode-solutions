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
    vector<int> postorderTraversal(TreeNode* root) {
           stack<TreeNode*>st;
        vector<int>ans;
        st.push(root);
        if(root==NULL){return {};}
        while(!st.empty())
        {
            TreeNode*temp=st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->left!=NULL)
            {
                st.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                st.push(temp->right);
            }


        }
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};