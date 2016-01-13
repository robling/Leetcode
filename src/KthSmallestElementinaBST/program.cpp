#include "../include/pre.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
int currentMinth;
bool gotKth;
int kthMin;
void helper(TreeNode* root, int k)
{
    if (!root) return;
    if (!gotKth) helper(root->left, k)
    currentMinth++;
    if (currentMinth == k) {
        kthMin = root->val;
        gotKth = true;
    }
    if (!gotKth) helper(root->right, k);
}

int kthSmallest(TreeNode* root, int k)
{
    currentMinth = 0;
    gotKth = false;
    kthMin = 0;
    helper(root, k);
    if (gotKth) return kthMin;
    else throw(std::exception("Not in this tree")); 
}