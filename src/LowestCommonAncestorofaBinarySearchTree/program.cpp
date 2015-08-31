#include "../include/pre.h"

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    //Make sure val of p less than val of q
    if (p->val > q->val) std::swap(p, q);
    auto it = root;
    while(it != NULL)
    {
        if (it->val <= q->val && it->val >= p->val)
            return it;
        else if (it->val > q->val)
            it = it->left;
        else
            it = it->right;
    }
}
