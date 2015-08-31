#include "../include/prevector.h"

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool ergodic(vector<TreeNode*>& path, TreeNode* root, TreeNode* d)
{
    if (root == NULL) return false;
    if (root == d) {
        path.push_back(root);
        return true;
    }
    if (ergodic(path, root->left, d)) {
        path.push_back(root);
        return true;
    }
    if (ergodic(path, root->right, d)) {
         path.push_back(root);
         return true;
    }
    return false;
}

vector<TreeNode*> pathToElem(TreeNode* root, TreeNode* d)
{
    vector<TreeNode*> path;
    ergodic(path, root, d);
    return path;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    auto pathToP = pathToElem(root, p);
    auto pathToQ = pathToElem(root, q);
    size_t i = 0;
    for (i = 0; i != std::min(pathToQ.size(), pathToP.size()); i++)
    {
        if (*(pathToQ.rbegin() + i) != *(pathToP.rbegin() + i)) break;
    }
    return *(pathToQ.rbegin() + i - 1);
}

int main()
{
    auto root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);
    cout << (root->right == lowestCommonAncestor(root, root->right->left, root->right->right)) << endl;
    return 0;
}
