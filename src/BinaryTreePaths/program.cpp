#include "../include/pre.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    string cur;
    vector<string> rst;
    bool helper(TreeNode* t) //return is_null
    {
        if (t == NULL) return true;
        auto tmp = cur;
        if (cur.size() != 0) cur += "->";
        cur += to_string(t->val);
        bool r = helper(t->left);
        r = helper(t->right) && r;
        if (r && cur.size() != 0) rst.push_back(cur);
        cur = tmp;
        return false;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        rst = decltype(rst)();
        cur = decltype(cur)();
        helper(root);
        return rst;
    }
};

int main()
{
    return 0;
}