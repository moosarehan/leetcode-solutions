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
int depth_first_search(vector<int>&tilts,TreeNode*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int sum1=depth_first_search(tilts,root->left);
    int sum2=depth_first_search(tilts,root->right);
    tilts.push_back(abs(sum1-sum2));
    return (sum1+sum2+root->val);

}
    int findTilt(TreeNode* root) {
        vector<int>tilts;
        int s=depth_first_search(tilts,root);
        s=0;
        for(int i=0;i<tilts.size();i++)
        {
            s+=tilts[i];
        }
        return s;
    }
};