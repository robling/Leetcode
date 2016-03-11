#include "../include/pre.h"

class Solution
{
private:
    vector<int> rst;
    void inorderTraversal_helper(TreeNode* it)
    {
        if (it == NULL) return;
        inorderTraversal_helper(it->left);
        rst.push_back(it->val);
        inorderTraversal_helper(it->right);
        return;
    }
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        rst.clear();
        inorderTraversal_helper(root);
        return rst;
    }
};