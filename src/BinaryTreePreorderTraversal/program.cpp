#include "../include/pre.h"
#include <stack>

class Solution {
private:
    std::stack<TreeNode*> cache;
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        if (root == NULL) return {};
        vector<int> rst;
        auto it = root;
        cache.push(it);
        while (!cache.empty())
        {
            it = cache.top();
            rst.push_back(it->val);
            cache.pop();
            if(it->right != NULL) cache.push(it->right);
            if(it->left != NULL) cache.push(it->left);
        }
        return rst;
    }
};