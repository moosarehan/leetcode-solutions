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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val==key)
        {
            //leaf node
            if(root->left==NULL&&root->right==NULL)
            {
                delete root;
                return NULL;
            }
            //1child
            else if(root->left==NULL)//right exsist
            {
                TreeNode*temp=root->right;
                delete root;
                return temp;

            }
             else if(root->right==NULL)//left exsist
            {
                TreeNode*temp=root->left;
                delete root;
                return temp;

            }
            else
            {
                //2 child
                TreeNode*child=root->left; //inorder predecssof
                TreeNode*parent=root;
                while(child->right!=NULL){
                    parent=child;
                  child=child->right;
                }
                if(parent==root)
                {
                    child->right=root->right;
                    delete root;
                    return child;
                }
                else
                {
                  //incase child has leftchild so
                  parent->right=child->left;
                  child->left=root->left;
                  child->right=root->right;
                  delete root;
                  return child;
                }
                
            }
        }
        else if(key<root->val)
        {
            root->left=deleteNode(root->left,key);
        }
        else
        {
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};