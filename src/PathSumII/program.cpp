#include "../include/pre.h"
#include <stack>

vector<vector<int>> rst;
std::vector<int> curPath;
void pathSum_helper(TreeNode* root, int sum)
{
    if (root == NULL) return;
    curPath.push_back(root->val);
    if (root->left == NULL && root->right == NULL && root->val == sum) 
    {
        rst.emplace_back(curPath);
    }
    else
    {
        pathSum_helper(root->left, sum - root->val);
        pathSum_helper(root->right, sum - root->val);
    }
    curPath.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int sum)
{
    rst = {};
    pathSum_helper(root, sum);
    return rst;
}