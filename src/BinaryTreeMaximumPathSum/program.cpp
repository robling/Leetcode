#include "../include/pre.h"

class Solution {
private:
    template<typename T, typename ...Targs>
    static T max(T t, Targs... args)
    {
        return max(t, max(args...));
    }
    template<typename T>
    static T max(T t1, T t2)
    {
        return std::max(t1, t2);
    }
    std::unordered_map<TreeNode*, int> maxChain;
    int maxValue;
    int maxPathSum_helper(TreeNode* root)
    {
        if (root == NULL) return 0;
        if (maxChain.find(root) != maxChain.end()) return maxChain[root];
        auto l = maxPathSum_helper(root->left);
        auto r = maxPathSum_helper(root->right);
        maxValue = max(maxValue, root->val, max(l, r, l + r) + root->val);
        maxChain[root] = root->val + std::max(0, std::max(l, r));
        return maxChain[root];
    }
public:
    int maxPathSum(TreeNode* root)
    {
        maxValue = std::numeric_limits<int>::min();
        maxPathSum_helper(root);
        return maxValue;
    }
};