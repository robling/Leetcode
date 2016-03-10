#include "../include/pre.h"

TreeNode* flatten_helper(TreeNode* root)
{
    cout << root->val << endl;
    if (root->left == NULL && root->right == NULL) return root;
    if (root->left == NULL) return flatten_helper(root->right);
    auto tmp = root->right;
    root->right = root->left;
    root->left = NULL;
    auto leftEndNode = flatten_helper(root->right);
    if (tmp != NULL) 
    {
        leftEndNode->right = tmp;
        return flatten_helper(tmp);
    }
    return leftEndNode;
}
void flatten(TreeNode* root)
{
    if (root == NULL) return;
    flatten_helper(root);
}